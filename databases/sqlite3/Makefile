# $NetBSD: Makefile,v 1.97 2015/05/20 11:33:01 abs Exp $

DISTNAME=	sqlite-autoconf-${SQLITE3_DISTVERSION}
PKGNAME=	sqlite3-${SQLITE3_VERSION}
CATEGORIES=	databases
MASTER_SITES=	http://www.hwaci.com/sw/sqlite/2015/ \
		http://www.sqlite.org/2015/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sqlite.org/
COMMENT=	SQL Database Engine in a C Library
LICENSE=	public-domain

.include "../../databases/sqlite3/Makefile.version"
.include "options.mk"

# On at least NetBSD 7.0_BETA amd64
# sqlite3.o: file not recognized: File truncated
# Makefile:404: recipe for target 'sqlite3' failed
MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	sqlite3.pc.in

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

# In the past, Linux had database corruption issues with pread, so
# only enable it on safe platforms.
CFLAGS.NetBSD+=		-DUSE_PREAD

# Darwin < 9 (Mac OS X < 10.5 "Leopard") doesn't have gethostuuid(2)
# and lacks the zone memory allocator
.if !empty(MACHINE_PLATFORM:MDarwin-[0-8].*-*)
CFLAGS+=		-DSQLITE_ENABLE_LOCKING_STYLE=0 -DSQLITE_WITHOUT_ZONEMALLOC
.endif

# This define includes the sqlite3_unlock_notify() API in the build.
# It is required by Firefox 4.x.
CFLAGS+=		-DSQLITE_ENABLE_UNLOCK_NOTIFY=1
# The following are defined in the NetBSD builtin version.
CFLAGS+=		-DSQLITE_ENABLE_COLUMN_METADATA
CFLAGS+=		-DSQLITE_ENABLE_LOAD_EXTENSION

# Uses dlopen and friends but doesn't use -ldl on Linux.
# See http://www.sqlite.org/cvstrac/tktview?tn=3555
LIBS+=			${BUILDLINK_LDADD.dl}

.if ${OS_VARIANT} == "SCOOSR5"
LDFLAGS.SCO_SV+=	-lpthread
.endif

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
