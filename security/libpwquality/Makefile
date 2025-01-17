# $OpenBSD: Makefile,v 1.13 2019/02/18 08:02:04 ajacoutot Exp $

COMMENT =		library to generate, and check strengh of passwords

V =			1.4.0
SUBST_VARS =		V
GH_PROJECT =		libpwquality
GH_ACCOUNT =		libpwquality
GH_TAGNAME =		libpwquality-${V}
DISTNAME =		libpwquality-${V}
REVISION =		1

SHARED_LIBS +=  pwquality            1.0      # 1.2

CATEGORIES =		security

MAINTAINER =		Jasper Lievisse Adriaanse <jasper@openbsd.org>, \
			Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2+
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB += ${MODPY_WANTLIB}
WANTLIB += c crack iconv intl pthread z

MODULES =		lang/python

USE_GMAKE =		Yes

BUILD_DEPENDS =		devel/gettext-tools \
			shells/bash

LIB_DEPENDS =		security/cracklib

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS =	--with-python-binary=python${MODPY_VERSION} \
			--with-python-rev=${MODPY_VERSION} \
			--with-sconfigdir=${SYSCONFDIR} \
			--disable-pam
CONFIGURE_ENV =		LDFLAGS="-L${LOCALBASE}/lib"

FAKE_FLAGS =		secureconfdir=${PREFIX}/share/examples/libpwquality/

AUTOCONF_VERSION =	2.69
AUTOMAKE_VERSION =	1.15
BUILD_DEPENDS +=	${MODGNU_AUTOCONF_DEPENDS} \
			${MODGNU_AUTOMAKE_DEPENDS} \
			devel/libtool
pre-configure:
	cd ${WRKSRC} && env -i \
		AUTOCONF_VERSION=${AUTOCONF_VERSION} \
		AUTOMAKE_VERSION=${AUTOMAKE_VERSION} \
		autoreconf -fi

.include <bsd.port.mk>
