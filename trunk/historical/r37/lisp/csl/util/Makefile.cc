###########################################################################
#                                                                         #
# makefile for REDUCE 3.7 using CSL                                       #
#                                                                         #
###########################################################################

# The following lines indicates the place on your disc where the "cslbase"
# directory exists. This is the  place where the C sources files for CSL
# live. There are two versions here, the first should use Unix-like
# file name conventions (in particular "/" as a directory separator) while
# the second will (in some cases) be a host-specific translation.

UCSLBASE  = ../cslbase
CSLBASE   = ../cslbase


###########################################################################

# Generic Unix with "cc". Note that if you use this you should review
# the file "machine.h" to ensure that CSL knows what name to report for
# your system. Also if the system you are running on needs more libraries
# scanned during the link phase. The Makefile create here will VERY
# probably need to be adjusted by hand.

CC        = cc
OPTFLAGS  = -O
MPIFLAGS  =
CFLAGS    = -c $(OPTFLAGS) -I$(CSLBASE) $(MPIFLAGS)
LIBS      = -lm -lcurses

###########################################################################

###########################################################################

SHELL     = /bin/sh
LINK      = $(CC)
LFLAGS    =
OUT       = -o
OUTOBJ    = -o
ASM       = $(CC)
ASMFLAGS  = $(CFLAGS)
ASMSRC    =
ASMOBJ    =
ASMOBJDEP = notused.obj
SYS       = sysunix
STORE     = -k8000
XSTORE    = -k8000
RM        = rm
MKDIR     = mkdir
COPY      = cp
STRIP     = strip
WX        =

###########################################################################


###########################################################################
###########################################################################
#                                                                         #
# This is the main bulk of the "makefile" for building Reduce 3.7 and CSL #
# on MSDOS, Windows and Unix.  This part of the file expects a number of  #
# symbols to have been defined:                                           #
#                                                                         #
# CSLBASE   = file-path for CSLBASE directory                             #
# CC        = The C compiler to use                                       #
# CFLAGS    = Flags for C compiler when compiling CSL                     #
# LINK      = Linker to use                                               #
# LFLAGS    = Flags for linker                                            #
# LIBS      = Libraries to quote to linker                                #
# OUT       = "-o" or "-out:"   See link commands                         #
# OUTOBJ    = "-o" often : where to put object code from C compilation    #
# ASM       = The assembler to use                                        #
# ASMFLAGS  = Flags for the assembler                                     #
# ASMSRC    = Assembly code source file to use                            #
# ASMOBJ    = Object file for above (or NULL if no assembly used)         #
# ASMOBJDEP = Ditto, but may not be NULL                                  #
# SYS       = name of system-specific file (sysdos or sysnt etc)          #
# STORE     = Memory option to pass to CSL (-k2500 is minimum)            #
# XSTORE    = Memory for the rebuild job that generates C code            #
# RM        = del for DOS, = rm for Unix                                  #
# MKDIR     = mkdir                                                       #
# COPY      = copy for DOS, = cp for Unix                                 #
# STRIP     = echo for DOS, = strip for Unix                              #
# SYMBOLIC  = .SYMBOLIC is using Watcom's "make" utility                  #
# WX        = wx for Windows 3.1, null in all other cases                 #
#                                                                         #
# The master version of this file is called "makebase" and is used to     #
# create both DOS and Unix makefiles.  Use the Codemist "makemake"        #
# program to perform the conversion - eg                                  #
#     makemake -f makebase -o makemake.386 watcom dos                     #
#     makemake -f makebase -o Makefile.sgi sgi                            #
# Just "makemake -f makebase" gives list of systems supported             #
###########################################################################
###########################################################################



###########################################################################
###########################################################################
#
# The main final target is r37.img, the image file for full REDUCE.
# If you want to rebuild stage-by-stage (eg while testing), try the
# sequence
#    make slowr37            compiles and links C coded kernel
#    make slowr37.img            makes bootstrap REDUCE
#                                 (roughly twice as slow as final one)
#                                 only used for system recompilation.
#    make profile                 runs tests, collects profile information.
#                                 This takes a long time!
#    make prof-inst               installs profile data
#    make c-code                  Create files u*.c and u*.lsp
#                                 out of hot-spot parts of REDUCE.
###########################################################################
# Note that only the steps from here downwards are usually needed
#
#    make r37                final compilation of most of REDUCE
#    make r37.img                build final image file
#    make testall                 runs test files, output to log directory
#    make checkall                creates log/checkall.log
#
# (for Windows 95/98/NT only)
#    make r37c.exe                command-line version
#
###########################################################################
###########################################################################


#
# C is another name for CSLBASE, the directory that CSL source files live
# in. I introduce it here mainly because $(C) is so much more compact
# then $(CSLBASE).
#

C =     $(CSLBASE)

#
# DOBJS is a list of all the object files that are common to all variants
# on the system built here
#

DOBJS =		arith01.o arith02.o arith03.o arith04.o \
		arith05.o arith06.o arith07.o arith08.o \
		arith09.o arith10.o arith11.o arith12.o \
		char.o csl.o cslmpi.o eval1.o eval2.o \
		eval3.o eval4.o fns1.o fns2.o fns3.o \
		print.o read.o restart.o $(ASMOBJ) \
		$(SYS).o

CDOBJS =	arith01.o,arith02.o,arith03.o,arith04.o,\
		arith05.o,arith06.o,arith07.o,arith08.o,\
		arith09.o,arith10.o,arith11.o,arith12.o,\
		char.o,csl.o,cslmpi.o,eval1.o,eval2.o,\
		eval3.o,eval4.o,fns1.o,fns2.o,fns3.o,\
		print.o,read.o,restart.o,$(ASMOBJ),\
		$(SYS).o

#
# OBJS adds in the files used when I am not building a demonstration-mode CSL
#

OBJS =		$(DOBJS) fasl.o gc.o preserve.o

COBJS =		$(CDOBJS),fasl.o,gc.o,preserve.o

#
# UOBJS come from that code that is compiled from Lisp into C
#

UOBJS =		u01.o u02.o u03.o u04.o u05.o \
		u06.o u07.o u08.o u09.o u10.o \
		u11.o u12.o

CUOBJS =	u01.o,u02.o,u03.o,u04.o,u05.o,\
		u06.o,u07.o,u08.o,u09.o,u10.o,\
		u11.o,u12.o


###########################################################################
###########################################################################

# This default target may be a dangerous one to use
# since it supposes that all the C code is up to date already.

default:	$(SYMBOLIC) \
		r37 r37.img



###########################################################################
###########################################################################

r37.img:	r37
	../util/full37

r37:	bytes.o $(OBJS) \
		$(UOBJS)
	$(LINK) $(LFLAGS) bytes.o $(OBJS) $(UOBJS) $(LIBS) $(OUT) r37 $(TAIL)
	$(STRIP) r37
	-$(MKDIR) log


#
# A few targets here may help me tidy up my filespace from time to time
#


clean: $(SYMBOLIC)
	-$(RM) slowr37
	-$(RM) slowr37.img
	-$(RM) r37
	-$(RM) r37.img
	-$(RM) csl
	-$(RM) csl.img
	-$(RM) *.o
	-$(MKDIR) log
	-$(RM) log/*.log


###########################################################################


csl:	bytes.o $(OBJS) \
		stubs.o
	$(LINK) $(LFLAGS) bytes.o $(OBJS) stubs.o $(LIBS) $(OUT) csl $(TAIL)
	$(STRIP) csl

slowr37:	bytes1.o $(OBJS) \
		stubs.o
	$(LINK) $(LFLAGS) bytes1.o $(OBJS) stubs.o $(LIBS) $(OUT) slowr37 $(TAIL)
	$(STRIP) slowr37
	-$(MKDIR) log


slowr37.img:	slowr37
	../util/boot37

profile:	slowr37.img $(SYMBOLIC)
	../util/profile

prof-inst:	profile.dat $(SYMBOLIC)
	$(COPY) profile.dat ../csl-c
	-$(RM) profile.dat

c-code:	slowr37.img $(SYMBOLIC)
	../util/c-code37

testslow:	slowr37.img $(SYMBOLIC)
	../util/testslow

testall:	r37.img $(SYMBOLIC)
	../util/testrest

checkall:	r37.img $(SYMBOLIC)
	../util/checkall

patchup:	r37.img $(SYMBOLIC)
	../util/patchup

cleanlog:	$(SYMBOLIC)
	-$(RM) ../../../log/*.rlg



csl.img:	csl $(C)/compat.lsp $(C)/compiler.lsp \
			$(C)/ccomp.lsp $(C)/extras.lsp
	-$(RM) csl.img
	$(WX) ./csl $(STORE) -v -z $(C)/build0.lsp \
		-D@cslbase="$(C)" -- log/cslimg.log

#
# "make lispfile"
#           recreates compiler.lsp, extras.lsp and ccomp.lsp from
#           the corresponding master sources which are held in RLISP
#           form.  Temporarily builds an RLISP parser on the way.
#       NB: only for system maintainance use.

lispfile:	csl csl.img $(C)/lispfile.lsp $(SYMBOLIC)
	$(WX) ./csl $(STORE) -v -z $(C)/lispfile.lsp \
		-D@cslbase="$(C)" -- log/lispfile.log

signature:	$(C)/version.hhh register.key $(SYMBOLIC)
	filesign -u $(C)/version.hhh $(C)/version.h Developer or tester


############################################################################
# Now rules for re-compiling the main collection of CSL source files. I
# write each case out individually since that makes the makefile less
# delicate than one that relies on setting up general rules - and I want this
# file to work on several different systems.
#

$(ASMOBJDEP):	$(C)/$(ASMSRC)
	$(ASM) $(ASMFLAGS) $(C)/$(ASMSRC)

arith01.o:	$(C)/arith01.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		$(C)/arith01.c

arith02.o:	$(C)/arith02.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		$(C)/arith02.c

arith03.o:	$(C)/arith03.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		$(C)/arith03.c

arith04.o:	$(C)/arith04.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		$(C)/arith04.c

arith05.o:	$(C)/arith05.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h $(C)/stream.h
	$(CC) $(CFLAGS) \
		$(C)/arith05.c

arith06.o:	$(C)/arith06.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		$(C)/arith06.c

arith07.o:	$(C)/arith07.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		$(C)/arith07.c

arith08.o:	$(C)/arith08.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		$(C)/arith08.c

arith09.o:	$(C)/arith09.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		$(C)/arith09.c

arith10.o:	$(C)/arith10.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		$(C)/arith10.c

arith11.o:	$(C)/arith11.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		$(C)/arith11.c

arith12.o:	$(C)/arith12.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		$(C)/arith12.c

bytes.o:	$(C)/bytes1.c $(C)/bytes.c $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h \
		$(C)/bytes.h $(C)/arith.h
	$(CC) $(CFLAGS) \
		$(C)/bytes.c

bytes1.o:	$(C)/bytes1.c $(C)/bytes.c $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h \
		$(C)/bytes.h $(C)/arith.h
	$(CC) $(CFLAGS) \
		$(C)/bytes1.c

#
# The target "bytes1a.o" recompiles bytes1.c, but with the flag set that
# arranges that the number of GET operations performed and the associated
# indicators will be recorded, so that (bytecounts) will display statistics
# about it. This slows things down considerably, but can help when you are in
# the process of deciding which indicators are specified as "fast" ones.
#

bytes1a.o:	$(C)/bytes1.c $(C)/bytes.c $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h \
		$(C)/bytes.h $(C)/arith.h
	$(CC) $(CFLAGS) -DRECORD_GET=1 \
		$(C)/bytes1.c

char.o:	$(C)/char.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		$(C)/char.c

csl.o:	$(C)/csl.c $(C)/tags.h $(C)/machine.h $(C)/externs.h $(C)/version.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/entries.h $(C)/stream.h $(C)/sockhdr.h
	$(CC) $(CFLAGS) \
		$(C)/csl.c



eval1.o:	$(C)/eval1.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/arith.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		$(C)/eval1.c

eval2.o:	$(C)/eval2.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/arith.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		$(C)/eval2.c

eval3.o:	$(C)/eval3.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		$(C)/eval3.c

eval4.o:	$(C)/eval4.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/arith.h
	$(CC) $(CFLAGS) \
		$(C)/eval4.c

fasl.o:	$(C)/fasl.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/arith.h
	$(CC) $(CFLAGS) \
		$(C)/fasl.c

fns1.o:	$(C)/fns1.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		$(C)/fns1.c

fns2.o:	$(C)/fns2.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/read.h $(C)/entries.h \
		$(C)/sockhdr.h
	$(CC) $(CFLAGS) \
		$(C)/fns2.c

fns3.o:	$(C)/fns3.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/read.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		$(C)/fns3.c

gc.o:	$(C)/gc.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		$(C)/gc.c

#
# For each major target I have one file that is system specific - eg
# sysdos.c, sysunix.c, ...
#

$(SYS).o:	$(C)/$(SYS).c $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/fileops.c $(C)/scandir.c $(C)/version.h \
		$(C)/filename.c
	$(CC) $(CFLAGS) \
		$(C)/$(SYS).c

preserve.o:	$(C)/preserve.c $(C)/tags.h $(C)/machine.h $(C)/stream.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h $(C)/read.h $(C)/version.h
	$(CC) $(CFLAGS) \
		$(C)/preserve.c

print.o:	$(C)/print.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/read.h \
		$(C)/arith.h $(C)/entries.h $(C)/stream.h $(C)/sockhdr.h
	$(CC) $(CFLAGS) \
		$(C)/print.c

read.o:	$(C)/read.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/read.h \
		$(C)/arith.h $(C)/entries.h $(C)/stream.h $(C)/sockhdr.h
	$(CC) $(CFLAGS) \
		$(C)/read.c

restart.o:	$(C)/restart.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/read.h $(C)/version.h \
		$(C)/arith.h $(C)/entries.h $(C)/stream.h
	$(CC) $(CFLAGS) \
		$(C)/restart.c

stubs.o:	$(C)/stubs.c $(C)/machine.h $(C)/externs.h $(C)/sys.h \
		$(C)/tags.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		$(C)/stubs.c

cslmpi.o:	$(C)/cslmpi.c $(C)/machine.h $(C)/externs.h $(C)/sys.h \
		$(C)/mpipack.c $(C)/tags.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		$(C)/cslmpi.c


###########################################################################

u01.o:	../csl-c/u01.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		../csl-c/u01.c

u02.o:	../csl-c/u02.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		../csl-c/u02.c

u03.o:	../csl-c/u03.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		../csl-c/u03.c

u04.o:	../csl-c/u04.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		../csl-c/u04.c

u05.o:	../csl-c/u05.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		../csl-c/u05.c

u06.o:	../csl-c/u06.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		../csl-c/u06.c

u07.o:	../csl-c/u07.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		../csl-c/u07.c

u08.o:	../csl-c/u08.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		../csl-c/u08.c

u09.o:	../csl-c/u09.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		../csl-c/u09.c

u10.o:	../csl-c/u10.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		../csl-c/u10.c

u11.o:	../csl-c/u11.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		../csl-c/u11.c

u12.o:	../csl-c/u12.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		../csl-c/u12.c


# end of makefile
