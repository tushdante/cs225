#**********************************************************
#  Macros
#   - These are simply variables that enable us to use
#       shorthand for certain commands or filenames.
#
#   - We use these later by using this syntax: $(COMPILER),
#       for example, for the COMPILER macro
#

# Name of the program
NAME_OF_EXECUTABLE_FILE_1 = testscene
NAME_OF_EXECUTABLE_FILE_2 = testimage


# We're using gcc for our compiling and linking
# Default options
COMPILER = g++
COMPILER_OPTS =-Wall -O0 -c -g

# We can define macros using other macros
LINKER = g++


# Object list
#   - In general, we will create an object file for every
#       .cpp file we have. These contain machine code
#       compiled from our source files, and will be
#       "linked" together to make our final program

OBJS_1 = EasyBMP.o image.o testscene.o scene.o
OBJS_2 = EasyBMP.o image.o testimage.o

#  End of macros
#**********************************************************

#**********************************************************
#  Linking rule
#   - This is what takes all of our object files and links
#       them together into one executable.
#
#   - The format for rules is:
#       filename : dependencies
#       	command line to run
#
#   - Note that we MUST USE *ACTUAL* TABS
#   
#   - This can use macros.
#
#   - "dependencies" are the files we need for this command
#       to work
#
#   - In this case, the command line to run will do the
#       linking of the object files we created
#


all: $(NAME_OF_EXECUTABLE_FILE_1) $(NAME_OF_EXECUTABLE_FILE_2)

$(NAME_OF_EXECUTABLE_FILE_1) : $(OBJS_1)
	$(LINKER) -o $(NAME_OF_EXECUTABLE_FILE_1) $(OBJS_1)
	
$(NAME_OF_EXECUTABLE_FILE_2) : $(OBJS_2)
	$(LINKER) -o $(NAME_OF_EXECUTABLE_FILE_2) $(OBJS_2)


#
#  End linking rule
#**********************************************************

#**********************************************************
#  Compiling rules for each object file
#   
#   - This is the same format as the linking rule above
#   
EASY_BMP_HEADERS= EasyBMP.h EasyBMP_BMP.h EasyBMP_DataStructures.h \
					EasyBMP_VariousBMPutilities.h 

EasyBMP.o : $(EASY_BMP_HEADERS) EasyBMP.cpp
	$(COMPILER) $(COMPILER_OPTS) EasyBMP.cpp

image.o : image.cpp image.h $(EASY_BMP_HEADERS)
	$(COMPILER) $(COMPILER_OPTS) image.cpp

testimage.o : testimage.cpp image.h $(EASY_BMP_HEADERS) 
	$(COMPILER) $(COMPILER_OPTS) testimage.cpp
	
scene.o : scene.cpp scene.h image.h $(EASY_BMP_HEADERS)
	$(COMPILER) $(COMPILER_OPTS) scene.cpp

testscene.o : testscene.cpp scene.h image.h $(EASY_BMP_HEADERS)
	$(COMPILER) $(COMPILER_OPTS) testscene.cpp
#
#  End compilation rules for objects
#**********************************************************

#**********************************************************
#  Clean rule
#
#   - run when using "make clean"
#   - deletes all files with extension .o and the
#       executable file
#

clean:
	-rm *.o $(NAME_OF_EXECUTABLE_FILE_1) $(NAME_OF_EXECUTABLE_FILE_2)

#
#  End clean rule
#**********************************************************
