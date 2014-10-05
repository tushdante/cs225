TIMING_EXE = timebst
TESTING_EXE = testbst
CXX = g++
CXX_FLAGS = -g -O0 -Wall
OBJS = main.o gnuplot.o seed.o
OBJS_TEST = testBST.o coloredout.o

all : $(TIMING_EXE) $(TESTING_EXE)

$(TIMING_EXE) : $(OBJS)
	$(CXX) -lrt -o $@ $(OBJS)

$(TESTING_EXE) : $(OBJS_TEST)
	$(CXX) -lrt -o $@ $(OBJS_TEST)

main.o: main.cpp bst.h bst.cpp bst_given.cpp gnuplot.h
	$(CXX) -c $(CXX_FLAGS) main.cpp

gnuplot.o: gnuplot.cpp gnuplot.h
	$(CXX) -c $(CXX_FLAGS) gnuplot.cpp

testBST.o: bst.h bst.cpp bst_given.cpp testBST.cpp
	$(CXX) -c $(CXX_FLAGS) testBST.cpp

coloredout.o: coloredout.cpp coloredout.h
	$(CXX) -c $(CXX_FLAGS) coloredout.cpp

tidy:
	-rm -f *.dat *.png *.log 2> /dev/null

clean:
	-rm -f $(TIMING_EXE) $(TESTING_EXE) 2> /dev/null
	-rm -f coloredout.o main.o gnuplot.o testBST.o 2> /dev/null
