# $OpenBSD: Makefile,v 1.19 2019/05/11 13:51:25 ajacoutot Exp $

COMMENT=		osinfo database files

V=			20190504
DISTNAME=		osinfo-db-${V}
EXTRACT_SUFX=		.tar.xz
REVISION=		0

PKG_ARCH=		*
NO_BUILD=		Yes
NO_TEST=		Yes

USE_GMAKE=		No

BUILD_DEPENDS=		misc/osinfo/osinfo-db-tools

CONFIGURE_STYLE=	# empty

do-install:
	osinfo-db-import --root ${WRKINST} --dir ${TRUEPREFIX}/share/osinfo \
		${FULLDISTDIR}/${DISTFILES}
# https://gitlab.com/libosinfo/osinfo-db/merge_requests/8
	${INSTALL_DATA} ${FILESDIR}/openbsd-6.5.xml \
		${PREFIX}/share/osinfo/os/openbsd.org/

.include <bsd.port.mk>
