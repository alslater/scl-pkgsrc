# $NetBSD: Makefile,v 1.18 2015/06/12 10:49:31 wiz Exp $
#

DISTNAME=	MooseX-Role-Parameterized-1.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ET/ETHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Role-Parameterized
COMMENT=	Roles with composition parameters
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Moose>=2.0300:../../devel/p5-Moose

BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Role/Parameterized/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

PERL5_PACKLIST=	auto/MooseX/Role/Parameterized/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
