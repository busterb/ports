# $OpenBSD: Makefile,v 1.4 2019/05/01 19:57:08 sthen Exp $

COMMENT =		require logged-in user for specified routes

MODULES =		cpan
PKG_ARCH =		*
DISTNAME =		Dancer2-Plugin-Auth-Tiny-0.005
CATEGORIES =		www
REVISION =		0

# Perl
PERMIT_PACKAGE_CDROM =	Yes

RUN_DEPENDS =		www/p5-Dancer2>=0.154000

TEST_DEPENDS =		www/p5-HTTP-Cookies \
			www/p5-HTTP-Message \
			www/p5-Plack
 
.include <bsd.port.mk>
