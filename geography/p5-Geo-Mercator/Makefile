# $NetBSD: Makefile,v 1.10 2015/06/12 10:50:08 wiz Exp $
#

DISTNAME=		Geo-Mercator-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
CATEGORIES=		geography perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Geo-Mercator/
COMMENT=		Perl5 module computing Mercator Projection into meters

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Geo/Mercator/.packlist

PREV_PKGPATH=		misc/p5-Geo-Mercator

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
