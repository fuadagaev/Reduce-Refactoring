# $Id$
#
# This Makefile is a temporary solution.
#
# libreduce.a is a library for using REDUCE from C programs
# communicating via sockets. It is restricted to unix-like systems.
#
# Say "make", and you will find "libreduce.a" in the subdirectory
# corresponding to your architecture. In a subdir "examples" there you
# will find an executable "lrtest". There is currently no written
# documentation yet. Instead, have a look at "src/lrtest.c" and
# "src/reduce.h".
#
# 03/2009 - T. Sturm (sturm@redlog.eu)

BUILD = $(shell ../../scripts/findhost.sh $(shell src/config.guess))

all:	
	cd src; \
	autoconf; \
	autoheader
	mkdir -p $(BUILD); \
	cd $(BUILD); \
	../src/configure --disable-universal; \
	$(MAKE)

clean:
	cd $(BUILD) && $(MAKE) clean

distclean: all
	cd $(BUILD) && $(MAKE) distclean
	/bin/rm -rf $(BUILD)
