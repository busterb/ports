# $OpenBSD: Makefile,v 1.24 2019/05/11 15:31:32 sthen Exp $

ONLY_FOR_ARCHS =	amd64 i386

COMMENT =		reference implementation of ACPI tools
DISTNAME =		acpica-unix-20190509
PKGNAME =		${DISTNAME:S/-unix//}

CATEGORIES =		devel

HOMEPAGE =		https://acpica.org/

MAINTAINER =		Stuart Henderson <sthen@openbsd.org>

# BSD-ish (or GPLv2 or Intel's own license: triple-licensed)
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =		c pthread

MASTER_SITES =		https://acpica.org/sites/acpica/files/

USE_GMAKE =		Yes
BUILD_DEPENDS =		devel/bison
MAKE_FLAGS =		CC="${CC}"
FAKE_FLAGS =		DESTDIR=

do-test:
	cd ${WRKSRC}/tests/templates && sh templates.sh 1

.include <bsd.port.mk>
