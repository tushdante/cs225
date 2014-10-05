
###############################################################################
#                                                                             #
#  CS225 Maze Makefile                                                        #
#                                                                             #
#  Author: Daniel Hoodin                                                      #
#  Date: Spring 2009                                                          #
#                                                                             #
###############################################################################

TEST_SQUARE_MAZE_EXE = testsquaremaze
TEST_DSETS_EXE = testdsets
TEST_DSETS_OBJS = testdsets.o dsets.o
TEST_SQUARE_MAZE_OBJS = testsquaremaze.o maze.o dsets.o EasyBMP.o

CXX = g++
CXX_OPTS = -g -O0 -Wall

.PHONY: all clean

all: $(TEST_DSETS_EXE) $(TEST_SQUARE_MAZE_EXE)

clean:
	-rm *.o $(TEST_DSETS_EXE) $(TEST_SQUARE_MAZE_EXE) 2>/dev/null

$(TEST_DSETS_EXE): $(TEST_DSETS_OBJS)
	$(CXX) -o $@ $^

$(TEST_SQUARE_MAZE_EXE): $(TEST_SQUARE_MAZE_OBJS)
	$(CXX) -o $@ $^

testdsets.o: testdsets.cpp dsets.o
	$(CXX) -c $(CXX_OPTS) $<

testsquaremaze.o: testsquaremaze.cpp dsets.o maze.o EasyBMP.o
	$(CXX) -c $(CXX_OPTS) $<

dsets.o: dsets.cpp dsets.h
	$(CXX) -c $(CXX_OPTS) $<

maze.o: maze.cpp maze.h dsets.o
	$(CXX) -c $(CXX_OPTS) $<

EasyBMP.o: EasyBMP.cpp EasyBMP.h
	$(CXX) -c $(CXX_OPTS) $<

