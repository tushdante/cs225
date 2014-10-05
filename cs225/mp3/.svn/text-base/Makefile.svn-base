
#*****************************************************
#  CS225 Spring 2009 MP3 Makefile
#*****************************************************

PART_ONE_EXE = mp3.1
PART_ONE_OBJS = EasyBMP.o testpartone.o

PART_TWO_EXE = mp3.2
PART_TWO_OBJS = EasyBMP.o testparttwo.o

COMPILER = g++
COMPILER_OPTS = -c -g -O0 -Wall
LINKER = g++
LINKER_OPTS = -o

all: $(PART_ONE_EXE) $(PART_TWO_EXE)

$(PART_ONE_EXE):  $(PART_ONE_OBJS)
	$(LINKER) $(LINKER_OPTS) $(PART_ONE_EXE) $(PART_ONE_OBJS)

$(PART_TWO_EXE):  $(PART_TWO_OBJS)
	$(LINKER) $(LINKER_OPTS) $(PART_TWO_EXE) $(PART_TWO_OBJS)

EasyBMP.o : EasyBMP.cpp EasyBMP.h
	$(COMPILER) $(COMPILER_OPTS) EasyBMP.cpp

testpartone.o : testpartone.cpp EasyBMP.o doubly-linked-list.h doubly-linked-list.cpp mp3extras.cpp
	$(COMPILER) $(COMPILER_OPTS) testpartone.cpp

testparttwo.o : testparttwo.cpp EasyBMP.o doubly-linked-list.h doubly-linked-list.cpp mp3extras.cpp
	$(COMPILER) $(COMPILER_OPTS) testparttwo.cpp

clean:
	-rm *.o $(PART_ONE_EXE) $(PART_TWO_EXE)

