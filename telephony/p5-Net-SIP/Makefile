# $OpenBSD: Makefile,v 1.45 2019/02/20 13:31:57 bluhm Exp $

COMMENT =	perl framework for SIP

DISTNAME =	Net-SIP-0.820

CATEGORIES =	net telephony

MAINTAINER =		Alexander Bluhm <bluhm@openbsd.org>

# Perl
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		cpan
RUN_DEPENDS =		net/p5-IO-Socket-INET6>=2.62 \
			net/p5-Net-DNS>=0.56 \
			security/p5-IO-Socket-SSL>=1.956

PKG_ARCH =		*

.include <bsd.port.mk>
