# $OpenBSD: Makefile,v 1.3 2019/05/07 13:56:51 sebastia Exp $

COMMENT =	framework to implement CMS scanners

DISTNAME =	cms_scanner-0.5.1
CATEGORIES =	security

MAINTAINER =	Sebastian Reitenbach <sebastia@openbsd.org>

# MIT
PERMIT_PACKAGE_CDROM=	Yes


MODULES =	lang/ruby
WANTLIB =	crypto ssl ${MODRUBY_WANTLIB}
NO_TEST =	Yes

BUILD_DEPENDS +=	${RUN_DEPENDS}
RUN_DEPENDS +=		devel/ruby-ruby-progressbar,${MODRUBY_FLAVOR},>=1.10,<1.11 \
			devel/ruby-opt_parse_validator,${MODRUBY_FLAVOR}>=1.7.2,<1.8 \
			devel/ruby-yajl,${MODRUBY_FLAVOR},>=1.4.1,<1.5 \
			net/ruby-public_suffix,${MODRUBY_FLAVOR},>=3.0,<3.1 \
			textproc/ruby-nokogiri,${MODRUBY_FLAVOR},>=1.10,<1.11 \
			www/ruby-typhoeus,${MODRUBY_FLAVOR},>=1.3,<1.4

CONFIGURE_STYLE =	ruby gem

.include <bsd.port.mk>
