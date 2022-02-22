DIRS = ASCII BACKUP BASIC C CPX DATUM DISKBASE \
	DISKCHAR DISKCHN DISKLIN DISKPAR DISKREK \
	DISKRND DISKVER HIFLOAT INT MATHE \
	PASBAS PASCAL PDM REGISTER RELOC SPEZIELL \
	VERSCHIE WANDEL ZEICHEN

OBJS = $(shell for i in $(DIRS) ; do echo $$i | sed 's,\(.*\),\1/\1.rel,' ; done)

include Makefile.inc

all clean install clobber::
	for i in $(DIRS) ; do \
		( cd $$i ; $(MAKE) $@ ) ; \
	done


