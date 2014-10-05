EXENAME=mp4
OBJS=mp4.o animation.o EasyBMP.o solidColorPicker.o gridColorPicker.o gradientColorPicker.o solnGradientColorPicker.o
BMPDIR=./mp4_lib/include/EasyBMP
IMGMAGICKCONFIG=-I./mp4_lib/include/ImageMagick -g -O2 -Wall -W -pthread
IMGMAGICKLINKOPTS=-L./mp4_lib/lib -lMagick++ -lMagickWand -lMagickCore
CC=g++
CCOPTS=-c
LINKER=g++

all: $(EXENAME)


$(EXENAME): $(OBJS)
	$(LINKER) -o $(EXENAME) $(OBJS) $(IMGMAGICKLINKOPTS)

mp4.o: mp4.cpp $(BMPDIR)/EasyBMP.h fills.h fills.cpp stack.h stack.cpp queue.h queue.cpp
	$(CC) $(CCOPTS) mp4.cpp -I$(BMPDIR) $(IMGMAGICKCONFIG)

EasyBMP.o: $(BMPDIR)/EasyBMP.h $(BMPDIR)/EasyBMP.cpp $(BMPDIR)/EasyBMP_BMP.h \
           $(BMPDIR)/EasyBMP_DataStructures.h $(BMPDIR)/EasyBMP_VariousBMPutilities.h
	$(CC) $(CCOPTS) $(BMPDIR)/EasyBMP.cpp

animation.o: animation.cpp animation.h
	$(CC) $(CCOPTS) animation.cpp  -I$(BMPDIR) $(IMGMAGICKCONFIG)

solidColorPicker.o: colorPicker.h solidColorPicker.cpp solidColorPicker.h
	$(CC) $(CCOPTS) solidColorPicker.cpp -I$(BMPDIR)

gridColorPicker.o: colorPicker.h gridColorPicker.cpp gridColorPicker.h
	$(CC) $(CCOPTS) gridColorPicker.cpp -I$(BMPDIR)

gradientColorPicker.o: colorPicker.h gradientColorPicker.cpp gradientColorPicker.h
	$(CC) $(CCOPTS) gradientColorPicker.cpp -I$(BMPDIR)

clean:
	rm -f $(EXENAME) $(EXENAME2)
