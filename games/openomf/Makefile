# $OpenBSD: Makefile,v 1.3 2019/05/10 06:20:18 bcallah Exp $

COMMENT =	free remake of One Must Fall 2097 game engine
DISTNAME =	openomf-0.6.5.2
CATEGORIES =	games x11

HOMEPAGE =	https://www.openomf.org/
MAINTAINER =	Brian Callahan <bcallah@openbsd.org>

# MIT
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += SDL2 argtable2 c confuse enet intl m openal png xmp
WANTLIB += z

MASTER_SITES =	https://mirrors.nycbug.org/pub/distfiles/

# C11
COMPILER =	base-clang ports-gcc

MODULES =	devel/cmake

LIB_DEPENDS =	audio/libxmp \
		audio/openal \
		devel/argtable \
		devel/libconfuse \
		devel/sdl2 \
		graphics/png \
		net/enet

NO_TEST =	Yes

# CONFIGURE_ARGS = -DCMAKE_C_FLAGS_RELEASE="${CFLAGS}" does not catch
do-gen:
	sed -i 's,-O2,${CFLAGS},g' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
