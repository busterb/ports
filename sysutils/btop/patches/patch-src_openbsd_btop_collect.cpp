This is based on https://github.com/aristocratos/btop/pull/1587
plus fixes to handle the number of active CPUs changing while btop is running.

Index: src/openbsd/btop_collect.cpp
--- src/openbsd/btop_collect.cpp.orig
+++ src/openbsd/btop_collect.cpp
@@ -122,15 +122,13 @@
 
 	void init() {
 		//? Shared global variables init
-		int mib[2];
-		mib[0] = CTL_HW;
-		mib[1] = HW_NCPU;
-		int ncpu;
-		size_t len = sizeof(ncpu);
-		if (sysctl(mib, 2, &ncpu, &len, nullptr, 0) == -1) {
+		int mib[] = {CTL_HW, HW_NCPUONLINE};
+		int ncpu_online;
+		size_t len = sizeof(ncpu_online);
+		if (sysctl(mib, 2, &ncpu_online, &len, nullptr, 0) == -1) {
 			Logger::warning("Could not determine number of cores, defaulting to 1.");
 		} else {
-			coreCount = ncpu;
+			coreCount = ncpu_online;
 		}
 
 		pageSize = sysconf(_SC_PAGE_SIZE);
@@ -389,13 +387,37 @@
 			Logger::error("failed to get load averages");
 		}
 
-		auto cp_time = std::unique_ptr<struct cpustats[]>{
-			new struct cpustats[Shared::coreCount]
-		};
-		size_t size = Shared::coreCount * sizeof(struct cpustats);
+		//? Read total physical CPU count for sysctl iteration
+		//? (may differ from coreCount when SMT is disabled via hw.smt=0).
+		int ncpu_total = Shared::coreCount;
+		{
+			int mib[] = {CTL_HW, HW_NCPU};
+			size_t len = sizeof(ncpu_total);
+			sysctl(mib, 2, &ncpu_total, &len, nullptr, 0);
+		}
+
+		//? Re-query online CPU count in case it changed at runtime (e.g. hw.smt toggled).
+		{
+			int mib[] = {CTL_HW, HW_NCPUONLINE};
+			int ncpu_online = Shared::coreCount;
+			size_t len = sizeof(ncpu_online);
+			if (sysctl(mib, 2, &ncpu_online, &len, nullptr, 0) != -1 and ncpu_online != Shared::coreCount) {
+				Shared::coreCount = ncpu_online;
+				core_old_totals.resize(Shared::coreCount, 0);
+				core_old_idles.resize(Shared::coreCount, 0);
+				cpu.core_percent.resize(Shared::coreCount);
+				cpu.temp.resize(Shared::coreCount + 1);
+				Runner::coreNum_reset = true;
+			}
+		}
+
+		auto cp_time = std::unique_ptr<struct cpustats[]>{
+			new struct cpustats[ncpu_total]
+		};
+		size_t size = sizeof(struct cpustats);
 		static int cpustats_mib[] = {CTL_KERN, KERN_CPUSTATS, /*fillme*/0};
-		for (int i = 0; i < Shared::coreCount; i++) {
-			cpustats_mib[2] = i / 2;
+		for (int i = 0; i < ncpu_total; i++) {
+			cpustats_mib[2] = i;
 			if (sysctl(cpustats_mib, 3, &cp_time[i], &size, NULL, 0) == -1) {
 				Logger::error("sysctl kern.cpustats failed");
 			}
@@ -404,11 +426,16 @@
 		long long global_idles = 0;
 		vector<long long> times_summed = {0, 0, 0, 0};
 
-		for (long i = 0; i < Shared::coreCount; i++) {
+		//? j iterates all physical CPUs; offline ones are skipped
+		//? i is the display slot index, incremented only for online CPUs
+		for (long i = 0, j = 0; j < ncpu_total; j++) {
+			if (!(cp_time[j].cs_flags & CPUSTATS_ONLINE))
+				continue;
+
 			vector<long long> times;
 			//? 0=user, 1=nice, 2=system, 3=idle
 			for (int x = 0; const unsigned int c_state : {CP_USER, CP_NICE, CP_SYS, CP_IDLE}) {
-				auto val = cp_time[i].cs_time[c_state];
+				auto val = cp_time[j].cs_time[c_state];
 				times.push_back(val);
 				times_summed.at(x++) += val;
 			}
@@ -423,7 +450,6 @@
 				global_idles += idles;
 
 				//? Calculate cpu total for each core
-				if (i > Shared::coreCount) break;
 				const long long calc_totals = max(0ll, totals - core_old_totals.at(i));
 				const long long calc_idles = max(0ll, idles - core_old_idles.at(i));
 				core_old_totals.at(i) = totals;
@@ -438,7 +464,7 @@
 				Logger::error("Cpu::collect() : " + (string)e.what());
 				throw std::runtime_error("collect() : " + (string)e.what());
 			}
-
+			i++;
 		}
 
 		const long long calc_totals = max(1ll, global_totals - cpu_old.at("totals"));
@@ -1218,7 +1244,7 @@
 				}
 				toggle_children = -1;
 			}
-			
+
 			if (auto find_pid = (collapse != -1 ? collapse : expand); find_pid != -1) {
 				auto collapser = rng::find(current_procs, find_pid, &proc_info::pid);
 				if (collapser != current_procs.end()) {
