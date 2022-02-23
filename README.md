This is an archive of the Werner Cisorvius software library,
with the intention of making the whole thing buildable and documented

as the esteemed Werner Cirsovius passed away in 2016, his work is unmaintained
as far as I know.  He built a lot of tools, and used them to disassemble 
commercial software and add significant functions to them.

BASELIB is his pretty comprehensive assembly language library; it is required by
a lot of his work.  in this tree, it has been modified to build with SLR180.

ZSID is the Digital Research Z80 debugger under cp/m.  Source has been unavailable,
so it has not been possible to fix a few bugs or enhance it until he did the work
to disassemble and contrive a way to build this program.  building it is complicated
by the need for ZSID to relocate itself into high memory to allow debug of programs
in the TPA.

I've enhanced ZSID to add disassembly of Z180 instructions and fixed a bug that prevented
the listing of ld A,R, and ld R,A.

it has been minimally tested, and the build process uses some of the RomWBW
build infrastructure to work, specifically the case-insensitive version of
zxcc.

there is much more to be added.  He was a Dynamo.

this source tree was fetched from https://mark-ogden.uk/mirrored.html
it is unfortunately expressed as a readable web site, not as source code
that can be built.  there are no makefiles or submit files.
