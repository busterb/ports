# $OpenBSD: Makefile,v 1.34 2019/03/13 20:27:40 sthen Exp $

# let's give it a chance?
#BROKEN-powerpc=	fails to build
#BROKEN-hppa =	fails to configure

COMMENT=	library for machine-independent, array-oriented data access

V=		4.6.3
NAME=		netcdf
DISTNAME=	${NAME}-c-${V}
PKGNAME=	${NAME}-${V}

CATEGORIES=	math

SHARED_LIBS=	netcdf		5.0 # 4.0

HOMEPAGE=	http://www.unidata.ucar.edu/software/netcdf/

MAINTAINER=	Martin Reindl <martin@catai.org>

# BSD
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB=		c m z pthread
WANTLIB+=		curl crypto nghttp2 ssl
WANTLIB+=		hdf5 hdf5_hl

LIB_DEPENDS =		net/curl \
			math/hdf5

TEST_DEPENDS=		shells/bash \
			textproc/gdiff

COMPILER =		base-clang ports-gcc base-gcc

MASTER_SITES=		ftp://ftp.unidata.ucar.edu/pub/netcdf/

CONFIGURE_STYLE= 	gnu
CONFIGURE_ENV+=		LDFLAGS="-L${LOCALBASE}/lib" \
			CPPFLAGS="-I${LOCALBASE}/include"

CONFIGURE_ARGS+=	--enable-shared \
			--disable-doxygen \
			--enable-netcdf-4 \
			--enable-dap \
			--prefix=${PREFIX}

USE_GMAKE=		Yes
SEPARATE_BUILD=		Yes

# https://github.com/Unidata/netcdf-c/issues/1347#issuecomment-467633543
# "Actually, I did not intend the .so files in netcdf-c/plugins to be
# installed. They are intended only for testing and examples"
post-install:
	rm ${PREFIX}/lib/lib{bzip2,misc}.{a,la,so}

.include <bsd.port.mk>
