# Created by: Sergei Kolobov <sergei@FreeBSD.org>
# $FreeBSD: head/mail/qmail-qfilter/Makefile 341864 2014-01-30 17:50:25Z pawel $

PORTNAME=	qmail-qfilter
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/${PORTNAME}/

MAINTAINER=	uffe@uffe.org
COMMENT=	Front-end for qmail-queue to run messages through filters

LIB_DEPENDS=	libbg-sysdeps.so:${PORTSDIR}/devel/bglibs

BGLIBS_INC=	${LOCALBASE}/include/bglibs
BGLIBS_LIB=	${LOCALBASE}/lib/bglibs

DOCS=		NEWS README TODO

do-configure:
	${ECHO_CMD} "${STAGEDIR}${PREFIX}/bin"	> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${STAGEDIR}${MANPREFIX}/man" > ${WRKSRC}/conf-man
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}"	> ${WRKSRC}/conf-ld
	${ECHO_CMD} "${BGLIBS_INC}"	> ${WRKSRC}/conf-bgincs
	${ECHO_CMD} "${BGLIBS_LIB}"	> ${WRKSRC}/conf-bglibs

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} samples/* ${STAGEDIR}${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
