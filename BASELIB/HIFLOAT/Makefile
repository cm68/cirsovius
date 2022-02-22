DIRS = $(shell for i in * ; do if [ -d $$i ] ; then echo $$i ; fi ; done)
OBJS = $(shell for i in $(DIRS) ; do echo $$i | sed 's,\(.*\),\1/\1.rel,' ; done)

all clean install clobber::
	for i in $(DIRS) ; do \
		( cd $$i ; $(MAKE) $@ ) ; \
	done

include ../Makefile.inc
