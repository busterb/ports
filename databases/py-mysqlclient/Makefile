# $OpenBSD: Makefile,v 1.9 2019/05/08 22:00:42 jca Exp $

COMMENT =		Python interface to MySQL

MODPY_EGG_VERSION =	1.4.2
DISTNAME =		mysqlclient-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME}

CATEGORIES =		databases

HOMEPAGE =		https://github.com/PyMySQL/mysqlclient-python/

# GPLv2
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += crypto m pthread ssl z
WANTLIB += lib/mysql/mysqlclient_r
WANTLIB += ${MODPY_WANTLIB}

MASTER_SITES =		${MASTER_SITE_PYPI:=m/mysqlclient/}

MODULES =		lang/python
MODPY_SETUPTOOLS =	Yes

FLAVORS =		python3
FLAVOR?=

LIB_DEPENDS = 		databases/mariadb

TEST_DEPENDS =		devel/py-mock${MODPY_FLAVOR} \
			devel/py-nose${MODPY_FLAVOR} \
			databases/mariadb

# You must setup a default.cnf file config and
# a MySQL server
TEST_IS_INTERACTIVE =		Yes

.include <bsd.port.mk>
