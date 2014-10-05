
#*****************************************************
#  CS225 Spring 2009 MP3 Makefile
#*****************************************************

OBJS = EasyBMP.o main.o
EXENAME = mp3

COMPILER = g++
COMPILER_OPTS = -c -g -O0 -Wall
LINKER = g++
LINKER_OPTS = -o

all: $(EXENAME)

$(EXENAME):  $(OBJS)
	$(LINKER) $(LINKER_OPTS) $(EXENAME) $(OBJS)

EasyBMP.o : EasyBMP.cpp EasyBMP.h
	$(COMPILER) $(COMPILER_OPTS) EasyBMP.cpp

main.o : main.cpp EasyBMP.o doubly-linked-list.h doubly-linked-list.cpp mp3extras.cpp
	$(COMPILER) $(COMPILER_OPTS) main.cpp

clean:
	-rm *.o $(EXENAME)

