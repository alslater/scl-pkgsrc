# $NetBSD: Makefile,v 1.16 2015/06/12 10:51:23 wiz Exp $

DISTNAME=	FormValidator-Simple-0.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FormValidator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/FormValidator-Simple/
COMMENT=	Validation with simple chains of constraints
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor>=0.22:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Accessor>=0.03:../../devel/p5-Class-Data-Accessor
DEPENDS+=	p5-Class-Data-Inheritable>=0.04:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Class-Inspector>=1.13:../../devel/p5-Class-Inspector
DEPENDS+=	p5-Date-Calc>=5.4:../../devel/p5-Date-Calc
DEPENDS+=	p5-DateTime-Format-Strptime>=1.0700:../../time/p5-DateTime-Format-Strptime
DEPENDS+=	p5-MailTools>=0:../../mail/p5-MailTools
DEPENDS+=	p5-Email-Valid>=0.15:../../mail/p5-Email-Valid
DEPENDS+=	p5-Email-Valid-Loose>=0.04:../../mail/p5-Email-Valid-Loose
DEPENDS+=	p5-Tie-IxHash>=1.21:../../devel/p5-Tie-IxHash
DEPENDS+=	p5-List-MoreUtils>=0.16:../../devel/p5-List-MoreUtils
DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=0}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-UNIVERSAL-require>=0.10:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-YAML>=0.39:../../textproc/p5-YAML

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/FormValidator/Simple/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
