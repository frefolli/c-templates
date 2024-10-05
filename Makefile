@all:

install:
	mkdir -p ${DESTDIR}/usr/include
	cp template.h ${DESTDIR}/usr/include
	mkdir -p ${DESTDIR}/usr/include/c-templates
	cp vector.h ${DESTDIR}/usr/include/c-templates
