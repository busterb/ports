# $OpenBSD: Makefile,v 1.1.1.1 2019/05/08 16:35:52 jasper Exp $

COMMENT =	pipe interface for radare2

MODPY_EGG_VERSION =	1.2.0
DISTNAME =	r2pipe-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	devel

HOMEPAGE =	https://rada.re

MAINTAINER =	Jasper Lievisse Adriaanse <jasper@openbsd.org>

# MIT
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/python
MODPY_PI =		Yes

FLAVORS =		python3
FLAVOR ?=

# There seems to be a python3-ism which breaks fake with python2:
# self.process = yield from create  # Init the process
# So fail if the on non-python3 flavor is set
.if !${FLAVOR:Mpython3}
ERRORS += "Fatal: Flavors other than python3 are not supported at the moment"
.endif

.include <bsd.port.mk>
