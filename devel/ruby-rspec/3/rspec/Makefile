#  $OpenBSD: Makefile,v 1.12 2019/04/04 06:21:04 naddy Exp $

COMMENT =		ruby framework for Behaviour Driven Development
V =			3.8.0
DISTNAME =		rspec-$V
REVISION =		0

BUILD_DEPENDS = 	${RUN_DEPENDS}
RUN_DEPENDS = 		devel/ruby-rspec/3/core,${MODRUBY_FLAVOR}>=$V \
			devel/ruby-rspec/3/expectations,${MODRUBY_FLAVOR}>=$V \
			devel/ruby-rspec/3/mocks,${MODRUBY_FLAVOR}>=$V

.include <bsd.port.mk>
