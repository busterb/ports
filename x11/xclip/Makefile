# $OpenBSD: Makefile,v 1.17 2019/04/24 16:26:59 sthen Exp $

COMMENT=		command line interface to X selections
GH_ACCOUNT=		astrand
GH_PROJECT=		xclip
GH_TAGNAME=		0.13
REVISION=		1
CATEGORIES=		x11

# GPLv2+
PERMIT_PACKAGE_CDROM=   Yes

WANTLIB+=		X11 Xmu c

BUILD_DEPENDS=		${MODGNU_AUTOCONF_DEPENDS} \
			${MODGNU_AUTOMAKE_DEPENDS}
NO_TEST=		yes
USE_GMAKE=		yes
CONFIGURE_STYLE=	gnu
CONFIGURE_ENV=		CPPFLAGS="-I${X11BASE}/include" \
			LDFLAGS="-L${X11BASE}/lib" \
			AUTOCONF_VERSION="${AUTOCONF_VERSION}" \
			AUTOMAKE_VERSION="${AUTOMAKE_VERSION}"
AUTOCONF_VERSION=	2.69
AUTOMAKE_VERSION=	1.15

post-patch:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -i

.include <bsd.port.mk>
