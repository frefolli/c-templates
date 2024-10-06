BUILDDIR=./builddir

@all: ${BUILDDIR}
	ninja -C ${BUILDDIR}

${BUILDDIR}: meson.build
	meson setup ${BUILDDIR} --reconfigure

clean:
	rm -rf ${BUILDDIR}

test:
	meson test -C ${BUILDDIR}

install:
	mkdir -p ${DESTDIR}/usr/include
	cp ./include/template.h ${DESTDIR}/usr/include
	mkdir -p ${DESTDIR}/usr/include/c-templates
	cp ./include/c-templates/vector.h ${DESTDIR}/usr/include/c-templates
	cp ./include/c-templates/map.h ${DESTDIR}/usr/include/c-templates
	cp ./include/c-templates/pair.h ${DESTDIR}/usr/include/c-templates
