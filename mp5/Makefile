#*****************************************************
#  CS225 Fall 2006 MP5 Makefile
#
#  File originally written by Matt Buchanan in Fall 1995
#
#*****************************************************


#**************************************************************************
# List of .o files that EXENAME depends on.  Edit as appropriate for MP.

OBJS = \
	EasyBMP.o quadtree.o main.o


#**************************************************************************
# Change this line if you don't like 'a.out'.

EXENAME = mp5


#**************************************************************************
# Macros defining the C/C++ compiler and linker.

CC = g++
CCOPTS = -g -Wall
LINK = g++
LINKOPTS = -o $(EXENAME)


#**************************************************************************
# Rules for building EXENAME from OBJS and OBJS from your source.

all: $(EXENAME)

$(EXENAME):  $(OBJS)
	$(LINK) $(LINKOPTS) $(OBJS)

clean:
	-rm *.o $(EXENAME)

EasyBMP.o : EasyBMP.cpp EasyBMP.h
	$(CC) -c $(CCOPTS) EasyBMP.cpp

quadtree.o : quadtree.cpp quadtree.h
	$(CC) -c $(CCOPTS) quadtree.cpp

main.o : main.cpp EasyBMP.o quadtree.o
	$(CC) -c $(CCOPTS) main.cpp

