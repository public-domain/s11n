# New ports collection makefile for:    libs11n
# Date created:         23 Nov 2005
# Whom:                 aaron@FreeBSD.org
#
# $FreeBSD: ports/devel/libs11n/Makefile,v 1.2 2006/08/01 04:44:01 aaron Exp $
#

PORTNAME=	libs11n
PORTVERSION=	1.3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	s11n
DISTNAME=	${PORTNAME}-${PORTVERSION}-nobuildfiles
EXTRACT_SUFX=	.zip

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	A C++ library for easily serializing a wide variety of objects

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_ZIP=	yes
USE_GCC=	3.2+
INSTALLS_SHLIB=	yes

post-extract:
	@${CP} ${PATCHDIR}/Makefile.bsd ${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${PREFIX}/include/s11n.net
	${MKDIR} ${PREFIX}/include/s11n.net/s11n
	${MKDIR} ${PREFIX}/include/s11n.net/s11n/io
	${MKDIR} ${PREFIX}/include/s11n.net/s11n/nodeutil
	${MKDIR} ${PREFIX}/include/s11n.net/s11n/plugin
	${MKDIR} ${PREFIX}/include/s11n.net/s11n/proxy
	${MKDIR} ${PREFIX}/include/s11n.net/s11n/proxy/pod
	${MKDIR} ${PREFIX}/include/s11n.net/s11n/proxy/std

.include <bsd.port.mk>
