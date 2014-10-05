
EXENAME = testheap
CXX = g++
CXX_FLAGS = -g -O0 -Wall
OBJS = testheap.o verify.o heapsort.o heapsorthelpers.o gnuplot.o

$(EXENAME) : $(OBJS)
	$(CXX) -lrt -o $@ $^

testheap.o: testheap.cpp minheap.h minheap.cpp verify.h
	$(CXX) -c $(CXX_FLAGS) testheap.cpp

heapsort.o: heapsort.cpp heapsort.h
	$(CXX) -c $(CXX_FLAGS) heapsort.cpp

#verify.o: verify.cpp verify.h
#	$(CXX) -c $(CXX_FLAGS) verify.cpp

#heapsorthelpers.o: heapsorthelpers.cpp heapsort.h
#	$(CXX) -c $(CXX_FLAGS) heapsorthelpers.cpp

gnuplot.o : gnuplot.cpp gnuplot.h
	$(CXX) -c $(CXX_FLAGS) gnuplot.cpp

clean:
	-rm -f $(EXENAME) 2> /dev/null
	-rm -f testheap.o heapsort.o 2> /dev/null
#	-rm -f verify.o heapsorthelpers.o 2> /dev/null
	-rm -f gnuplot.o

tidy:
	-rm -f *.dat *.png *.log
