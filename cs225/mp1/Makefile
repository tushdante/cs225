# MAKEFILE for mp1

#

#
# Object files are listed here
#
OBJS = main.o EasyBMP.o 

#
# Change your program name here
#
EXENAME = mp1

#
# Recognize these macro assignments (like g++), but leave them alone.
#
CC = g++
CCOPTS = -c -g -O0 -Wall
LINK = g++
LINKOPTS = -o

all : $(EXENAME)

#
# The main compiling step, using all macros.
#
$(EXENAME) : $(OBJS)
	$(LINK) $(LINKOPTS) $(EXENAME) $(OBJS)

#
# Here is where your work will be done
#
main.o : main.cpp EasyBMP.o 
	$(CC) $(CCOPTS) main.cpp
	
EasyBMP.o : EasyBMP.cpp EasyBMP.h EasyBMP_BMP.h EasyBMP_DataStructures.h EasyBMP_VariousBMPutilities.h 
	$(CC) $(CCOPTS) EasyBMP.cpp	

clean : 
	rm -f *.o $(EXENAME) 2>/dev/null

