COMMENT=	migrate repositories from CVS to Subversion/GIT/BZR

# Python 3 port, tracking github.com/busterb/cvs2svn's python3-port
#
MODPY_DISTV=	3.0.0.dev0
DISTNAME=	cvs2svn-${MODPY_DISTV}
PKGNAME=	cvs2svn-${MODPY_DISTV}

EPOCH=		0

GH_ACCOUNT=	busterb
GH_PROJECT=	cvs2svn
GH_TAGNAME=	python3-port-2

WRKDIST=	${WRKDIR}/${GH_PROJECT}-${GH_TAGNAME}

CATEGORIES=	devel

HOMEPAGE=	https://github.com/mhagger/cvs2svn

# BSD-like
PERMIT_PACKAGE=	Yes

MODULES=	lang/python
MODPY_PYBUILD=	setuptools

TEST_FLAGS=	PYTHON=${MODPY_BIN}

TEST_TARGET=	check

DOCFILES=	BUGS.md CHANGES.md COPYING HACKING.md README.md \
		doc/design-notes.txt
DOCDIR=		${PREFIX}/share/doc/cvs2svn
EXAMPLEDIR=	${PREFIX}/share/examples/cvs2svn

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR} ${EXAMPLEDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${DOCFILES} ${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/cvs2*-example.options ${EXAMPLEDIR}

.include <bsd.port.mk>
