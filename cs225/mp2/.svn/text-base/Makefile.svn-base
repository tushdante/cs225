#**********************************************************
# Makefile -- part of mp2
# MAKEFILE for mp2
# Sept 6, 2010
#**********************************************************

#
# Object files are listed here
#
OBJS = testimage.o EasyBMP.o image.o
OBJS2 = testscene.o image.o EasyBMP.o scene.o

#
# Change your program name here
#
EXENAME = testimage
EXENAME2 = testscene

#
# Recognize these macro assignments (like g++), but leave them alone.
#
CC = g++
CCOPTS = -c -g -O0 -Wall
LINK = g++
LINKOPTS = -o

all : $(EXENAME) $(EXENAME2)

#
# The main compiling step, using all macros.
#
$(EXENAME) : $(OBJS)
	$(LINK) $(LINKOPTS) $(EXENAME) $(OBJS)

$(EXENAME2) : $(OBJS2)
	$(LINK) $(LINKOPTS) $(EXENAME2) $(OBJS2)

#
# Here is where your work will be done
#
testimage.o : testimage.cpp EasyBMP.o image.o 
	$(CC) $(CCOPTS) testimage.cpp

image.o: image.cpp image.h
	$(CC) $(CCOPTS) image.cpp

EasyBMP.o : EasyBMP.cpp EasyBMP.h EasyBMP_BMP.h EasyBMP_DataStructures.h EasyBMP_VariousBMPutilities.h 
	$(CC) $(CCOPTS) EasyBMP.cpp

scene.o : scene.cpp scene.h
	$(CC) $(CCOPTS) scene.cpp

testscene.o : testscene.cpp EasyBMP.o image.o scene.o 
	$(CC) $(CCOPTS) testscene.cpp

clean : 
	rm -f *.o $(EXENAME) 2>/dev/null
	rm -f *.o $(EXENAME2) 2>/dev/null

#Checks for differences
#diff:
#	diff scene.bmp soln_scene.bmp
#	diff scene2.bmp soln_scene2.bmp
#	diff scene3.bmp soln_scene3.bmp
#	diff scene4.bmp soln_scene4.bmp
#	diff scene5.bmp soln_scene5.bmp
#	diff scene6.bmp soln_scene6.bmp
#	diff scene5.bmp soln_scene6.bmp
#	diff scene6.bmp soln_scene5.bmp
#	diff scene7.bmp soln_scene7.bmp
#	diff scene8.bmp soln_scene8.bmp
#	diff scene7.bmp soln_scene8.bmp
#	diff scene8.bmp soln_scene7.bmp

#Checks for memory leak
#leak:
#	valgrind --leak-check=full ./testimage
#	valgrind --leak-check=full ./testscene
	
