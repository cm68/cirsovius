ROOT = $(shell pwd | sed 's/Disassembler.*$$//')
ZX = zxcc
M80 = M80.COM
L80 = L80.COM

OBJECTS = m80kern.rel m80cmd.rel m80io.rel m80date.rel m80ver.rel

all:	M80.COM

clean:
	rm -f *.lst *.sym $(OBJECTS)

clobber: clean
	rm -f M80.COM

%.rel: %.mac
	$(ZX) $(M80) = +$(basename $<)

m80kern.rel: m80kern.mac m80.lib \
	m80kern.001 m80kern.002 m80kern.003 \
	m80kern.004 m80kern.005 m80kern.006
m80cmd.rel:  m80cmd.mac  m80.lib
m80io.rel:   m80io.mac   m80.lib
m80date.rel: m80date.mac m80.lib
m80ver.rel:  m80ver.mac  m80.lib

M80.COM: $(OBJECTS)
	$(ZX) $(L80) m80kern,m80cmd,m80io,m80date,m80ver,m80/N
	mv m80.com M80.COM
