# $OpenBSD: Makefile,v 1.20 2018/11/21 13:12:37 bket Exp $

COMMENT =	SSL/SSH multiplexer

DISTNAME =	sslh-v1.20
PKGNAME =	${DISTNAME:S/-v/-/}
CATEGORIES =	security net

HOMEPAGE =	https://www.rutschle.net/tech/sslh/README.html

MAINTAINER =	Bjorn Ketelaars <bket@openbsd.org>

# GPLv2+
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =	c config pcre

MASTER_SITES =	https://www.rutschle.net/tech/sslh/

LIB_DEPENDS =	devel/libconfig \
		devel/pcre

MAKE_FLAGS =	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lconfig -lpcre" \
		MAN=sslh.8

USE_GMAKE =	Yes

NO_TEST =	Yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sslh
	${INSTALL_DATA} ${WRKSRC}/README.md ${PREFIX}/share/doc/sslh
	${INSTALL_MAN} ${WRKSRC}/sslh.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/sslh
.for p in basic.cfg example.cfg
	${INSTALL_DATA} ${WRKSRC}/$p ${PREFIX}/share/examples/sslh
.endfor
.for p in sslh-fork sslh-select
	${INSTALL_PROGRAM} ${WRKSRC}/$p ${PREFIX}/sbin
.endfor

.include <bsd.port.mk>
