# $NetBSD: Makefile,v 1.106 2015/06/30 10:20:10 ryoon Exp $

DISTNAME=	libgd-2.1.1
PKGNAME=	${DISTNAME:S/libgd/gd/}
CATEGORIES=	graphics
MASTER_SITES=	https://bitbucket.org/libgd/gd-libgd/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://libgd.bitbucket.org/
COMMENT=	Graphics library for the dynamic creation of images

#WRKSRC=		${WRKDIR}/${DISTNAME:S/libgd-/libgd-gd-/}

.include "options.mk"

USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-fontconfig=${BUILDLINK_PREFIX.fontconfig}
CONFIGURE_ARGS+=	--with-freetype=${BUILDLINK_PREFIX.freetype2}
CONFIGURE_ARGS+=	--with-jpeg=${BUILDLINK_PREFIX.jpeg}
CONFIGURE_ARGS+=	--with-png=${BUILDLINK_PREFIX.png}
CONFIGURE_ARGS+=	--with-tiff=${BUILDLINK_PREFIX.tiff}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
REPLACE_PERL+=		src/bdftogd
PTHREAD_AUTO_VARS=	yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
