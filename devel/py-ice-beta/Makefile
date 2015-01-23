# Created by: Michael Gmelin <freebsd@grem.de>
# $FreeBSD: #

CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd@grem.de
COMMENT=	Ice (Internet Communications Engine) language mapping for Python

LICENSE=	GPLv2

BUILD_DEPENDS=	mcpp:${PORTSDIR}/devel/mcpp \
		slice2py:${PORTSDIR}/devel/ice-beta
LIB_DEPENDS=	libIce.so.${LIB_VRS}:${PORTSDIR}/devel/ice-beta

USES=		python
SLAVE_PORT=	yes
MASTERDIR=	${.CURDIR}/../ice-beta
PLIST=		${.CURDIR}/pkg-plist

BUILD_WRKSRC=	${WRKSRC}/py
INSTALL_WRKSRC=	${WRKSRC}/py

MAKE_ENV+=	PYTHON_VERSION=${PYTHON_VERSION}

LIB_VRS=	${PORTVERSION:S|.||g:C|[0-9]$||}
PLIST_SUB=	LIB_VERSION="${PORTVERSION}" LIB_VRS="${LIB_VRS}"

# bypass infrastructure bug (taken from www/py-django)
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	DEBUG DOCS TESTS
OPTIONS_DEFAULT=TESTS
TESTS_DESC=	Run tests

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYSITEDIR}/Ice/*.so.*
	${ECHO} "Ice" > ${STAGEDIR}${PYSITEDIR}/Ice.pth
	@${FIND} ${STAGEDIR}${PYSITEDIR}/Ice \( -name "*.pyc" -or -name "*.pyo" \) \
		-exec ${CHMOD} u+w {} \;
	@${PYTHON_CMD} -m compileall -d ${PYSITEDIR}/Ice ${STAGEDIR}${PYSITEDIR}/Ice
	@${PYTHON_CMD} -O -m compileall -d ${PYSITEDIR}/Ice ${STAGEDIR}${PYSITEDIR}/Ice

.include "${MASTERDIR}/Makefile"
