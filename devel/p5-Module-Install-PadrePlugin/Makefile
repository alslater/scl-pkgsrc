# $NetBSD: Makefile,v 1.8 2015/06/12 10:49:27 wiz Exp $

DISTNAME=	Module-Install-PadrePlugin-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Install-PadrePlugin/
COMMENT=	Module::Install support for Padre plugins
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-Install>=0.77:../../devel/p5-Module-Install
DEPENDS+=	p5-PAR-Dist>=0.17:../../devel/p5-PAR-Dist

PERL5_PACKLIST=		auto/Module/Install/PadrePlugin/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
