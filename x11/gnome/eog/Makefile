# $OpenBSD: Makefile,v 1.151 2019/05/08 13:07:14 jasper Exp $

COMMENT=		Eye of GNOME, image viewing and cataloging program

GNOME_PROJECT=		eog
GNOME_VERSION=		3.32.1

CATEGORIES=		graphics

# GPLv2
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB += X11 c cairo exempi exif gdk-3 gdk_pixbuf-2.0 gio-2.0
WANTLIB += girepository-1.0 glib-2.0 gnome-desktop-3 gobject-2.0
WANTLIB += gtk-3 intl jpeg lcms2 m peas-1.0 peas-gtk-1.0 rsvg-2
WANTLIB += z pthread
WANTLIB += atk-1.0 cairo-gobject gmodule-2.0 pango-1.0 pangocairo-1.0

MODULES=		devel/dconf \
			devel/meson \
			x11/gnome

BUILD_DEPENDS=		devel/gsettings-desktop-schemas

LIB_DEPENDS=		devel/libpeas \
			graphics/lcms2 \
			graphics/libexif \
			textproc/exempi \
			x11/gnome/desktop

RUN_DEPENDS=		devel/gsettings-desktop-schemas

MODGNOME_TOOLS += desktop-file-utils gobject-introspection yelp
MODGNOME_TOOLS += gtk-update-icon-cache shared-mime-info

.include <bsd.port.mk>
