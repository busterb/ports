# $OpenBSD: Makefile,v 1.3 2019/04/28 20:51:44 sthen Exp $

COMMENT =	pcap bgp parser

MODPY_EGG_VERSION =	0.2.18
DISTNAME =	pbgpp-${MODPY_EGG_VERSION}
REVISION =	0

CATEGORIES =	net

MAINTAINER =	Peter Hessler <phessler@openbsd.org>

# Apache 2.0
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/python
MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes
MODPY_VERSION =		${MODPY_DEFAULT_VERSION_3}

RUN_DEPENDS =		net/py-pcapy${MODPY_FLAVOR}
BUILD_DEPENDS +=	${RUN_DEPENDS}

.include <bsd.port.mk>
