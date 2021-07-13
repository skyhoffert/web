#
# Sky Hoffert
# Makefile for web repository.
# Created on Jul-12-2021.
# Last modified on Jul-12-2021.
#

BINDIR=bin/
INCDIR=include/
OBJDIR=obj/
SRCDIR=src/
TESTDIR=tests/

CPP=g++
CPPFLAGS=-std=c++2a -Wall
INCLUDE=-I$(INCDIR)
LINKS=
LIBS=

# Here, all targets are listed.
TARGETS=$(OBJDIR)web.obj

all: $(TARGETS)

tests: $(BINDIR)web.test

clean:
	$(info Cleaning.)
	rm -rf $(OBJDIR)*.obj
	rm -rf $(BINDIR)*.test

###############################################################################
# Main program is defined below.
###############################################################################



###############################################################################
# Object recipes are defined below.
###############################################################################

$(OBJDIR)web.obj: \
		$(SRCDIR)web.cpp \
		$(INCDIR)web.hpp
	$(info Building web.)
	$(CPP) $(CPPFLAGS) $(LINKS) $(INCLUDE) -o $(OBJDIR)web.obj -c \
		$(SRCDIR)web.cpp \
		$(LIBS)

###############################################################################
# Test recipes are defined below.
###############################################################################

$(BINDIR)web.test: \
		$(OBJDIR)web.obj \
		$(TESTDIR)web.test.cpp
	$(info Building web test.)
	$(CPP) $(CPPFLAGS) $(LINKS) $(INCLUDE) -o $(BINDIR)web.test \
		$(TESTDIR)web.test.cpp \
		$(OBJDIR)web.obj
		$(LIBS)
