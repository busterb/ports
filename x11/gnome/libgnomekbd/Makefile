# $OpenBSD: Makefile,v 1.61 2019/02/08 17:43:17 jasper Exp $

COMMENT=		keyboard configuration library

GNOME_PROJECT=		libgnomekbd
GNOME_VERSION=		3.26.1

SHARED_LIBS +=  gnomekbd             8.0      # 8.0
SHARED_LIBS +=  gnomekbdui           8.0      # 8.0

CATEGORIES=		devel

# LGPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += X11 Xcomposite Xcursor Xdamage Xext Xfixes Xi Xinerama
WANTLIB += Xrandr Xrender atk-1.0 atk-bridge-2.0 c cairo cairo-gobject
WANTLIB += epoxy expat ffi fontconfig freetype fribidi gdk-3 gdk_pixbuf-2.0
WANTLIB += gio-2.0 glib-2.0 gmodule-2.0 gobject-2.0 graphite2
WANTLIB += gthread-2.0 gtk-3 harfbuzz iconv intl lzma m pango-1.0
WANTLIB += pangocairo-1.0 pangoft2-1.0 pcre pixman-1 png16 pthread
WANTLIB += xcb xcb-render xcb-shm xkbfile xklavier xml2 z

MODULES=		devel/dconf \
			x11/gnome

MODGNOME_TOOLS=		desktop-file-utils gobject-introspection
MODGNOME_CPPFLAGS=	-I${X11BASE}/include

LIB_DEPENDS=		x11/gnome/libxklavier \
			x11/gtk+3

CONFIGURE_STYLE=	gnu

.include <bsd.port.mk>
