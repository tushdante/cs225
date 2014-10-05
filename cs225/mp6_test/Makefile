
##
# Makefile
#
# Simple Makefile to build photomosaic program
# and tests
#
#  Authors:
#  Matt Sachtler
#  Scott Wegner
#
#  Developed for CS225 PhotoMosaic MP
#  Fall 2008
#  
#  Updates:
#  	Spring 2009 - Matt Sachtler - removed KDElement
##

EXENAME=photomosaic
KDTEXENAME=testkdtree
KDTMEXENAME=testkdtilemapper

I_GRAPHICSMAGICK=-I../mp6_lib/include
I_XML=-I/usr/include/libxml2
L_FLICKCURL=-lflickcurl
L_GRAPHICSMAGICK=-Wl,-rpath -Wl,../mp6_lib/lib -lGraphicsMagick++ -lGraphicsMagick

LIB=-L../mp6_lib/lib $(L_FLICKCURL) $(L_GRAPHICSMAGICK)

OBJS = main.o flickr.o image.o imagereader.o local.o mosaiccanvas.o \
	photomosaic.o plugin.o sourceimage.o tileimage.o kdtilemapper.o \
	tilemapper.o

KDTOBJS = testkdtree.o 
KDTMOBJS = testkdtilemapper.o image.o imagereader.o mosaiccanvas.o sourceimage.o \
	   tileimage.o kdtilemapper.o tilemapper.o 

COMPILER=g++
LINKER=g++
COMPILER_OPTS=-c -g -O0 -Wall 
LINKER_OPTS=$(LIB) -o

all : $(EXENAME)
test : $(KDTMEXENAME) $(KDTMEXENAME)
check : $(KDTEXENAME) $(KDTMEXENAME)
	./$(KDTEXENAME)
	./$(KDTMEXENAME)

$(EXENAME) : $(OBJS)
	$(LINKER) $(LINKER_OPTS) $(EXENAME) $(OBJS)

$(KDTEXENAME) : $(KDTOBJS)
	$(LINKER) $(LINKER_OPTS) $(KDTEXENAME) $(KDTOBJS)

$(KDTMEXENAME) : $(KDTMOBJS)
	$(LINKER) $(LINKER_OPTS) $(KDTMEXENAME) $(KDTMOBJS)

main.o : photomosaic.o main.cpp
	$(COMPILER) $(COMPILER_OPTS) $(I_GRAPHICSMAGICK) main.cpp

flickr.o : plugin.o flickr.h flickr.cpp
	$(COMPILER) $(COMPILER_OPTS) $(I_GRAPHICSMAGICK) $(I_XML) flickr.cpp

image.o : image.h image.cpp
	$(COMPILER) $(COMPILER_OPTS) $(I_GRAPHICSMAGICK) image.cpp

imagereader.o : sourceimage.o tileimage.o imagereader.h imagereader.cpp
	$(COMPILER) $(COMPILER_OPTS) $(I_GRAPHICSMAGICK) imagereader.cpp

local.o : plugin.o local.h local.cpp
	$(COMPILER) $(COMPILER_OPTS) local.cpp

mosaiccanvas.o : tileimage.o mosaiccanvas.h mosaiccanvas.cpp
	$(COMPILER) $(COMPILER_OPTS) $(I_GRAPHICSMAGICK) mosaiccanvas.cpp

photomosaic.o : local.o flickr.o photomosaic.h photomosaic.cpp
	$(COMPILER) $(COMPILER_OPTS) $(I_GRAPHICSMAGICK) photomosaic.cpp

plugin.o : plugin.h plugin.cpp
	$(COMPILER) $(COMPILER_OPTS) plugin.cpp

sourceimage.o : image.o sourceimage.h sourceimage.cpp
	$(COMPILER) $(COMPILER_OPTS) $(I_GRAPHICSMAGICK) sourceimage.cpp

tileimage.o : image.o tileimage.h tileimage.cpp
	$(COMPILER) $(COMPILER_OPTS) $(I_GRAPHICSMAGICK) tileimage.cpp

tilemapper.o : mosaiccanvas.o sourceimage.o tileimage.o tilemapper.h tilemapper.cpp
	$(COMPILER) $(COMPILER_OPTS) $(I_GRAPHICSMAGICK) tilemapper.cpp

kdtilemapper.o : mosaiccanvas.o sourceimage.o tilemapper.o tileimage.o kdtilemapper.h kdtilemapper.cpp
	$(COMPILER) $(COMPILER_OPTS) $(I_GRAPHICSMAGICK) kdtilemapper.cpp

testkdtilemapper.o : testkdtilemapper.cpp kdtilemapper.o imagereader.o
	$(COMPILER) $(COMPILER_OPTS) $(I_GRAPHICSMAGICK) testkdtilemapper.cpp

testkdtree.o : testkdtree.cpp kdtree.h kdtree.cpp
	$(COMPILER) $(COMPILER_OPTS) testkdtree.cpp

clean:
	rm -f $(EXENAME) $(KDTEXENAME) $(KDTMEXENAME) *.o 2>/dev/null

