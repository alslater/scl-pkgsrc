# $NetBSD: Makefile,v 1.12 2015/06/12 10:49:33 wiz Exp $
#

DISTNAME=	MooseX-Types-URI-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Types-URI/
COMMENT=	URI related types and coercions for Moose
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=0:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types>0.40:../../devel/p5-MooseX-Types
DEPENDS+=	p5-MooseX-Types-Path-Class>0:../../devel/p5-MooseX-Types-Path-Class
DEPENDS+=	p5-URI>0:../../www/p5-URI
DEPENDS+=	p5-URI-FromHash>0:../../www/p5-URI-FromHash

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Types/URI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
