# $NetBSD: Makefile,v 1.10 2015/06/12 10:48:45 wiz Exp $

PKGNAME=	${DISTNAME:C/-/91-/}
PKGREVISION=	1
COMMENT=	Robust, next generation, object-relational DBMS

DEPENDS+=	postgresql91-client>=${PKGVERSION_NOREV}:../../databases/postgresql91-client
DEPENDS+=	postgresql91-docs>=${PKGVERSION_NOREV}:../../databases/postgresql91-docs
DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

META_PACKAGE=	yes

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
