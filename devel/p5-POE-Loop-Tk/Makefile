# $OpenBSD: Makefile,v 1.14 2018/12/02 01:05:59 afresh1 Exp $

COMMENT=		bridge that allows POE to be driven by Tk

DISTNAME=		POE-Loop-Tk-1.305
CATEGORIES=		devel
FIX_EXTRACT_PERMISSIONS=Yes

MODULES=		cpan
PKG_ARCH=		*

# perl
PERMIT_PACKAGE_CDROM=	Yes

CONFIGURE_ARGS+=	--default

BUILD_DEPENDS=		devel/p5-POE-Test-Loops>=1.352
RUN_DEPENDS+=		x11/p5-Tk \
			devel/p5-POE>=1.367
TEST_DEPENDS=		devel/p5-Term-Size \
			net/p5-Socket-GetAddrInfo

TEST_IS_INTERACTIVE= x11

.include <bsd.port.mk>
