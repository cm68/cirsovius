ROOT = $(shell pwd | sed 's/BASELIB.*$$/BASELIB/')

ZX = $(HOME)/src/RomWBW/Tools/Linux/zx 
SLR180 = $(ROOT)/../SLR/SLR180.COM
LIB = /usr/local/lib/cpm/bin80/LIB.COM

ifndef DIRS
LINKS = $(notdir $(shell echo $(ROOT)/INCLUDE/*.lib)) 
endif

HERE = $(notdir $(shell pwd))

SRCS = $(shell echo *.180)
OBJS ?= $(addsuffix .rel,$(basename $(SRCS)))
ALLOBJS = $(shell echo $(basename $(OBJS)) | tr ' ' ',')

LIBRARY = $(HERE).rel
LIBROOT = $(basename $(LIBRARY))
LOWLIB	= $(shell echo $(LIBRARY) | tr 'A-Z' 'a-z')

all::	$(LIBRARY)

clean::
	echo $(HERE)
	rm -f $(OBJS) *.lst

clobber:: clean
	rm -f $(LIBRARY) $(basename $(OBJS))
	for i in $(LINKS) ; do if [ -L $$i ] ; then rm $$i ; fi ; done

%.rel: %.180
	$(ZX) $(SLR180) -$(basename $<).@@z/MF

ifndef DIRS
$(LINKS):
	ln -s $(ROOT)/INCLUDE/$@ $@
$(OBJS): $(LINKS)
else
$(OBJS):
	for i in $(DIRS) ; do \
		(cd $$i ; $(MAKE) ) ; \
	done
endif

$(LIBRARY): $(OBJS)
	rm -f $(LIBRARY) $(LOWLIB)
	for i in $(basename $(OBJS)) ; do \
		if [ $$(dirname $$i) = '.' ] ; then \
			fi=$$i ; \
		else \
			fi=$$(basename $$i) ; \
			cp $$i.rel $$fi.rel ; \
		fi ; \
		if [ -f $(LOWLIB) ] ; then \
			echo $(ZX) $(LIB) $(LIBROOT)=$(LIBROOT),$$fi ; \
			$(ZX) $(LIB) $(LIBROOT)=$(LIBROOT),$$fi > /dev/null ; \
		else \
			echo $(ZX) $(LIB) $(LIBROOT)=$$fi ; \
			$(ZX) $(LIB) $(LIBROOT)=$$fi > /dev/null ; \
		fi ; \
		if [ $$(dirname $$i) != '.' ] ; then rm $$fi.rel ; fi ; \
	done;
	mv $(LOWLIB) $(LIBRARY)

