# $OpenBSD: Makefile,v 1.13 2019/02/26 22:10:54 bentley Exp $

COMMENT =		n64 emulator sdl audio plugin

# GPLv2+
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB =		SDL2 samplerate speexdsp
LIB_DEPENDS =		audio/speexdsp \
			devel/sdl2 \
			audio/libsamplerate

MUPEN64PLUS_MOD = 	audio-sdl

.include <bsd.port.mk>
