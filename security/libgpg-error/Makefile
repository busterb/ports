# $OpenBSD: Makefile,v 1.49 2019/03/20 16:32:29 ajacoutot Exp $

COMMENT=		error codes for GnuPG related software

DISTNAME=		libgpg-error-1.36
CATEGORIES=		security devel
EXTRACT_SUFX=		.tar.bz2

SHARED_LIBS +=  gpg-error            3.19     # 27.0

HOMEPAGE=		https://www.gnupg.org/software/libgpg-error/index.html

MAINTAINER=		Antoine Jacoutot <ajacoutot@openbsd.org>

# GPLv2 - LGPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += c iconv intl

MASTER_SITES=		${MASTER_SITE_GNUPG:=libgpg-error/}

LIB_DEPENDS=		devel/gettext

CONFIGURE_STYLE=	gnu

USE_GMAKE=		Yes

.include <bsd.port.mk>
