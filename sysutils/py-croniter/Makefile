# $OpenBSD: Makefile,v 1.10 2019/04/28 20:51:53 sthen Exp $

COMMENT =		datetime-iterator for cron-like formats

MODPY_EGG_VERSION =	0.3.30
DISTNAME =		croniter-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME}
REVISION =		0

CATEGORIES =		sysutils

MAINTAINER =		Jasper Lievisse Adriaanse <jasper@openbsd.org>

# MIT
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/python
MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes

FLAVORS =		python3
FLAVOR ?=

RUN_DEPENDS =		devel/py-dateutil${MODPY_FLAVOR}
TEST_DEPENDS =		${RUN_DEPENDS}

.include <bsd.port.mk>
