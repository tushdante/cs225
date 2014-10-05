#
# This makefile is designed to make three programs:
#	exercise0  from 'make exercise1'
#	exercise1  from 'make exercise2'
#	exercise2  from 'make exercise3'
#

EXE = sketchify

OBJS = main.o EasyBMP.o

COMPILER = g++
COMPILER_OPTS = -c -g -O0 -w
LINKER = g++
LINKER_OPTS = -o

all : $(EXE)

$(EXE) : $(OBJS)
	$(LINKER) $(LINKER_OPTS) $(EXE) $(OBJS)

main.o : main.cpp EasyBMP.h
	$(COMPILER) $(COMPILER_OPTS) main.cpp
	
EasyBMP.o : EasyBMP.cpp EasyBMP.h
	$(COMPILER) $(COMPILER_OPTS) EasyBMP.cpp

clean : 
	rm -f *.o $(EXE)

