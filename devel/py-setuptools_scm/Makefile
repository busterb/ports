# $OpenBSD: Makefile,v 1.11 2019/04/28 20:51:36 sthen Exp $

COMMENT =		plugin to manage your versions by scm tags

MODPY_EGG_VERSION =	2.0.0
DISTNAME =		setuptools_scm-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME}
CATEGORIES =		devel
REVISION =		0

MAINTAINER =		Alexandr Shadchin <shadchin@openbsd.org>

# MIT
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/python

TEST_DEPENDS =		devel/git \
			devel/mercurial \
			devel/py-pip${MODPY_FLAVOR}

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes
MODPY_PYTEST =		Yes

FLAVORS =		python3
FLAVOR ?=

do-test:
	@rm ${WRKSRC}/testing/test_setuptools_support.py
	@${MODPY_TEST_TARGET}

.include <bsd.port.mk>
