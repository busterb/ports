# $OpenBSD: Makefile,v 1.25 2019/02/24 07:54:17 feinerer Exp $

COMMENT=	edit enlightenment's keybindings

DISTNAME=	e16-keyedit-0.9
PKGNAME=	${DISTNAME:S/-//}
CATEGORIES=    	x11

# X11
PERMIT_PACKAGE_CDROM=	Yes

WANTLIB =  X11 Xcomposite Xcursor Xdamage Xext Xfixes Xi
WANTLIB += Xinerama Xrandr Xrender atk-1.0 c cairo
WANTLIB += fontconfig freetype gdk-x11-2.0 gdk_pixbuf-2.0 gio-2.0
WANTLIB += glib-2.0 gobject-2.0 gtk-x11-2.0
WANTLIB += intl pango-1.0 pangocairo-1.0 pangoft2-1.0
WANTLIB += z

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=enlightenment/}

LIB_DEPENDS=	x11/gtk+2
RUN_DEPENDS=	enlightenment->=1.0.7:x11/enlightenment

CONFIGURE_STYLE=gnu

.include <bsd.port.mk>
