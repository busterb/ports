# $OpenBSD: Makefile,v 1.2 2019/04/28 20:51:37 sthen Exp $

COMMENT =		hack to explicitly set up and tear down fixtures

MODPY_EGG_VERSION =	0.1.1
DISTNAME =		pytest-subtesthack-${MODPY_EGG_VERSION}
PKGNAME =		py-test-subtesthack-${MODPY_EGG_VERSION}
REVISION =		0

CATEGORIES =		devel

# Public Domain
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/python
MODPY_PI =		Yes
MODPY_SETUPTOOLS=	Yes

RUN_DEPENDS =		devel/py-test${MODPY_FLAVOR}

FLAVORS =		python3
FLAVOR ?=

.include <bsd.port.mk>
