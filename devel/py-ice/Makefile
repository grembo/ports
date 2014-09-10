# Created by: Boris B. Samorodov <bsam@ipt.ru>
# $FreeBSD: head/devel/py-ice/Makefile 364453 2014-08-09 16:09:28Z mva $

CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd@grem.de
COMMENT=	Ice (Internet Communications Engine) language mapping for Python

LICENSE=	GPLv2

BUILD_DEPENDS=	mcpp:${PORTSDIR}/devel/mcpp \
		slice2py:${PORTSDIR}/devel/ice

USES=		python
MASTERDIR=	${.CURDIR}/../ice
PLIST=		${.CURDIR}/pkg-plist

BUILD_WRKSRC=	${WRKSRC}/py
INSTALL_WRKSRC=	${WRKSRC}/py

MAKE_ENV+=	PYTHON_VERSION=${PYTHON_VERSION}

# bypass infrastructure bug (taken from www/py-django)
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	DEBUG DOCS TESTS
OPTIONS_DEFAULT=TESTS
TESTS_DESC=	Run tests

post-install:
	${ECHO} "Ice" > ${STAGEDIR}${PYSITEDIR}/Ice.pth
	@${FIND} ${STAGEDIR}${PYSITEDIR}/Ice \( -name "*.pyc" -or -name "*.pyo" \) \
		-exec ${CHMOD} u+w {} \;
	@${PYTHON_CMD} -m compileall ${STAGEDIR}${PYSITEDIR}/Ice
	@${PYTHON_CMD} -O -m compileall ${STAGEDIR}${PYSITEDIR}/Ice

.include "${MASTERDIR}/Makefile"
