# $NetBSD: Makefile,v 1.11 2015/01/01 08:23:53 dholland Exp $

DISTNAME=	libdiscid-0.6.1
CATEGORIES=	audio
MASTER_SITES=	http://ftp.musicbrainz.org/pub/musicbrainz/libdiscid/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/libdiscid
COMMENT=	Library for creating MusicBrainz DiscIDs
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	libdiscid.pc.in

.include "../../mk/bsd.pkg.mk"
