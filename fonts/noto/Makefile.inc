# $OpenBSD: Makefile.inc,v 1.4 2019/05/10 04:14:13 bentley Exp $

DISTNAME ?=		noto-${NOTO_PROJECT}-${V:S/-//g}

CATEGORIES ?=		fonts

HOMEPAGE ?=		https://www.google.com/get/noto/

# SIL OFL 1.1
PERMIT_PACKAGE_CDROM ?=	Yes

MAINTAINER ?=		Anthony J. Bentley <anthony@anjbe.name>

GH_ACCOUNT ?=		googlei18n
GH_PROJECT ?=		noto-${NOTO_PROJECT}

NO_BUILD ?=		Yes
NO_TEST ?=		Yes
PKG_ARCH ?=		*

NOTO_INSTALLDIR ?=	${PREFIX}/share/fonts/noto
