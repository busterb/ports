# $OpenBSD: Makefile,v 1.15 2019/01/06 16:02:22 naddy Exp $

COMMENT=	test VT100-type terminal

DISTNAME=	vttest-20190105
CATEGORIES=	misc
HOMEPAGE=	http://invisible-island.net/vttest/vttest.html

MAINTAINER=	Christian Weisgerber <naddy@openbsd.org>

# MIT
PERMIT_PACKAGE_CDROM=	Yes

MASTER_SITES=	http://invisible-mirror.net/archives/vttest/ \
		ftp://ftp.invisible-island.net/vttest/
EXTRACT_SUFX=	.tgz

WANTLIB=	c

CONFIGURE_STYLE=gnu
MAKE_FILE=	makefile

.include <bsd.port.mk>
