# $NetBSD: Makefile,v 1.51 2015/04/25 14:23:18 tnn Exp $

DISTNAME=	qiv-2.3.1
PKGREVISION=	1
CATEGORIES=	graphics x11
MASTER_SITES=	http://spiegl.de/qiv/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://spiegl.de/qiv/
COMMENT=	Quick Image Viewer
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/qiv share/pixmaps
INSTALLATION_DIRS+=	share/applications

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
