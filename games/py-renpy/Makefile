# $NetBSD: Makefile,v 1.9 2015/06/30 09:57:35 ryoon Exp $

DISTNAME=	renpy-6.16.5-source
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-source//}
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.renpy.org/dl/6.16.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.renpy.org/
COMMENT=	Visual Novel Engine written in Python
LICENSE=	mit

USE_TOOLS+=	pax

PYSETUPSUBDIR=	module
EGG_NAME=	Ren_Py-${PKGVERSION_NOREV}.525
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 6.16.5

RENPY_DEPS_INSTALL+=	${BUILDLINK_PREFIX.SDL}
RENPY_DEPS_INSTALL+=	${BUILDLINK_PREFIX.freetype2}
RENPY_DEPS_INSTALL+=	${BUILDLINK_PREFIX.zlib}
RENPY_DEPS_INSTALL+=	${BUILDLINK_PREFIX.ffmpeg010}/${BUILDLINK_LIBDIRS.ffmpeg010}

MAKE_ENV+=	RENPY_DEPS_INSTALL=${RENPY_DEPS_INSTALL:ts;:S,;,::,g:Q}

INSTALLATION_DIRS=	bin

REPLACE_PYTHON=		renpy.py launcher/game/tkaskdir.py

RENPY_DIR=		share/renpy

pre-configure:
	cd ${WRKSRC} && find . -name '*.py[co]' -print -delete

post-install:
	cd ${WRKSRC}; ${FIND} doc launcher renpy template the_question \
		tutorial update \
		-type f \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/${RENPY_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/renpy.py ${DESTDIR}${PREFIX}/${RENPY_DIR}
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -fs ../${RENPY_DIR}/renpy.py .

.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/py-game/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../multimedia/ffmpeg010/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
