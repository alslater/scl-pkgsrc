# $NetBSD: Makefile,v 1.12 2015/06/12 10:52:07 wiz Exp $

DISTNAME=	LWP-Authen-Wsse-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/LWP-Authen-Wsse/
COMMENT=	Library for enabling X-WSSE authentication in LWP

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64

PERL5_PACKLIST=		auto/LWP/Authen/Wsse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
