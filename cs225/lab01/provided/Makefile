#
# USING THIS MAKEFILE:
#
#	Every target has been filled in for you except for the apartment.o 
# target.  Write this one on your own, and then type 'make' to
# compile your program.  You could also type 'make lab01', but
# make automatically selects the first target in the file.  Use
# 'make clean' to start the process from scratch.
#

#
# Object files are listed here
#
OBJS = main.o apartment.o 

#
# Change your program name here
#
EXENAME = lab01

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
main.o : main.cpp apartment.o 
	$(CC) $(CCOPTS) main.cpp
	
apartment.o : apartment.cpp apartment.h
	$(CC) $(CCOPTS) apartment.cpp	

clean : 
	rm -f *.o $(EXENAME) 2>/dev/null

