# $OpenBSD: Makefile,v 1.54 2019/02/18 19:50:32 jasper Exp $

ONLY_FOR_ARCHS=		${APM_ARCHS}

COMMENT=		generate a statusbar for use with i3/xmobar/dzen2

DISTNAME=		i3status-2.12
CATEGORIES=		x11 sysutils
REVISION=		4

HOMEPAGE=		https://i3wm.org/i3status/

MAINTAINER=		Jasper Lievisse Adriaanse <jasper@openbsd.org>

# BSD
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.tar.bz2

WANTLIB += c confuse m pthread yajl

USE_GMAKE=		Yes

BUILD_DEPENDS=		textproc/asciidoc>=8.6.8
LIB_DEPENDS=		devel/libconfuse \
			devel/libyajl

NO_TEST=		Yes

MAKE_ENV+=		V=1 SYSCONFDIR=${PREFIX}/share/examples/i3status/

pre-configure:
	${SUBST_CMD} ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/i3status ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/i3status
	${INSTALL_DATA} ${WRKSRC}/i3status.conf \
		${PREFIX}/share/examples/i3status/
	${INSTALL_MAN} ${WRKSRC}/man/i3status.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
