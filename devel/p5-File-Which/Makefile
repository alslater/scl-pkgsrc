# $NetBSD: Makefile,v 1.16 2015/06/12 10:49:15 wiz Exp $

DISTNAME=	File-Which-1.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Which/
COMMENT=	Portable implementation of the 'which' utility
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=		p5-Test-Script>=1.05:../../devel/p5-Test-Script
BUILD_DEPENDS+=		{perl>=5.10.1,p5-Test-Simple>=0.80}:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/File/Which/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
