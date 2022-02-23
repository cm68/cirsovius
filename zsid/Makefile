ROOT=..
ZX = $(HOME)/src/RomWBW/Tools/Linux/zx
SLR180 = ../SLR/SLR180.COM
M80 = ~/src/RomWBW/Tools/cpm/bin/M80.COM
LINK = /usr/local/lib/cpm/bin80/DRLINK.COM

all:	ZSID.COM

OBJECTS = LDBLD.REL BDOS.REL BREAK.REL CCRLF.REL COMOUT.REL CONOUT.REL ERROR.REL \
	SKPBLK.REL SKPITM.REL FPARSE.REL

clean:
	rm -f *.lst *.sym $(OBJECTS) SIDRELO.SPR \
	XSIDLOAD.REL LDBLD.COM XSIDLOAD.COM SIDRELO.REL

clobber: clean
	rm -f ZSID.COM

%.REL: %.MAC
	$(ZX) $(M80) = +$(basename $<)
	mv $(shell echo $@ | tr 'A-Z' 'a-z') $@	

XSIDLOAD.COM: XSIDLOAD.REL
	$(ZX) $(LINK) +xsidload[NR]
	mv xsidload.com XSIDLOAD.COM

SIDRELO.SPR: SIDRELO.REL
	$(ZX) $(LINK) -sidrelo[OS]
	mv sidrelo.spr SIDRELO.SPR

LDBLD.COM:	$(OBJECTS)
	$(ZX) $(LINK) +ldbld,error,bdos,conout,comout,skpblk,break,skpitm,ccrlf,fparse[NR]
	mv ldbld.com LDBLD.COM

SIDRELO.REL:	SIDRELO.MAC SIDCMD.MAC ZSIDLA.MAC XSID.LIB

#
# this does not work, because ZX does not do CPM+ parse call!
#
ZSID.COM:	LDBLD.COM SIDRELO.SPR XSIDLOAD.COM
	rm -f zsid.com
	$(ZX) LDBLD.COM -XSIDLOAD.COM -SIDRELO.SPR -ZSID.COM
	mv zsid.com ZSID.COM

TEST.COM: TEST.180
	$(ZX) $(SLR180) -TEST/F

hd:	TEST.COM ZSID.COM
	(cd ~/src/RomWBW/Source/CPNET3 ; make hd)
