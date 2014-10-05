#
# USING THIS MAKEFILE:
#
#  'make treefun' - creates test executable
#

OBJS = main.o coloredout.o
EXENAME = treefun

CC = g++
CCOPTS = -g -O0 -Wall
LINK = g++
LINKOPTS = 

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LINK) $(LINKOPTS) -o $(EXENAME) $(OBJS)

main.o : main.cpp binarytree.h binarytree.cpp extras.cpp coloredout.h
	$(CC) -c $(CCOPTS) main.cpp

coloredout.o: coloredout.cpp coloredout.h
	$(CC) -c $(CCOPTS) $(@:.o=.cpp)

clean :
	rm -f *.o $(EXENAME)

