# $OpenBSD: Makefile,v 1.12 2019/05/10 19:11:13 ajacoutot Exp $

COMMENT=	small and fast AV1 decoder

VER=		0.3.0
DISTNAME=	dav1d-${VER}
REVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://code.videolan.org/videolan/dav1d/-/archive/${VER}/
EXTRACT_SUFX=	.tar.bz2

SHARED_LIBS=	dav1d	2.0

HOMEPAGE=	https://code.videolan.org/videolan/dav1d/

MAINTAINER=	Brad Smith <brad@comstyle.com>

# BSD
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB=	c pthread

MODULES=	devel/meson

COMPILER=	base-clang ports-gcc
COMPILER_LANGS=	c

.if ${MACHINE_ARCH} == "amd64"
BUILD_DEPENDS+=	devel/nasm
.endif

.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=-Dbuild_asm=false
.endif

.include <bsd.port.mk>
