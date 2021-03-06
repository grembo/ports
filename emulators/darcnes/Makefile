# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD: head/emulators/darcnes/Makefile 340722 2014-01-22 17:00:46Z mat $

PORTNAME=	darcnes
PORTVERSION=	9b0401
PORTREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	http://www.dridus.com/~nyef/darcnes/download/ \
		http://blog.grem.de/distfiles/ \
		ftp://ftp.debian.nl/pub/freebsd/ports/distfiles/
DISTNAME=	dn${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	multi-system emulator

NO_CDROM=	Commercial use is restricted

WRKSRC=		${WRKDIR}/${PORTNAME}

WANT_GNOME=	yes
USES=		gmake
MAKE_ARGS=	CC="${CC}" TARGET_CC="${CC}" CXX="${CXX}" TARGET_CXX="${CXX}" \
		AS="${AS}" TARGET_AS="${CC}" LD="${LD}" TARGET_LD="${CC}"

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" || defined(WITHOUT_X86_ASM)
MAKE_ARGS+=	C_ONLY=-DC_ONLY
.else
MAKE_ARGS+=	MACH_TYPES=-DMACH_TYPES=\\\"types-i386.h\\\"
.endif

.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME=	gtk12
MAKE_ARGS+=	TARGET=Linux_GTK
PKGNAMESUFFIX=	-gtk
.else
.if defined(WITH_SVGALIB)
LIB_DEPENDS+=	vga:${PORTSDIR}/graphics/svgalib
MAKE_ARGS+=	TARGET=Linux_svgalib
PKGNAMESUFFIX=	-svgalib
.else
USE_XORG=	x11 xaw xext xmu xt
.endif
.endif

post-patch:
	@${CP} ${FILESDIR}/endian.h ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/darcnes ${STAGEDIR}${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
