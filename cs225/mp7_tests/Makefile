
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
TEST_ALL_EXE = testall
TEST_DSETS_OBJS = dsetstest.o dsets.o
TEST_SQUARE_MAZE_OBJS = squaremazetest.o maze.o dsets.o EasyBMP.o
CLEAN_OBJS = dsetstest.o dsets.o squaremazetest.o maze.o dsets.o EasyBMP.o

CXX = g++
CXX_OPTS = -g -O0 -Wall

.PHONY: all clean

all: $(TEST_DSETS_EXE) $(TEST_SQUARE_MAZE_EXE)

clean:
	-rm $(CLEAN_OBJS) $(TEST_ALL_EXE) $(TEST_DSETS_EXE) $(TEST_SQUARE_MAZE_EXE) 2>/dev/null

$(TEST_ALL_EXE): $(TEST_DSETS_OBJS) $(TEST_SQUARE_MAZE_OBJS) testall.o
	$(CXX) -o $@ $^ goodmaze.o gooddsets.o

$(TEST_DSETS_EXE): $(TEST_DSETS_OBJS) testdsets.o
	$(CXX) -o $@ $^

$(TEST_SQUARE_MAZE_EXE): $(TEST_SQUARE_MAZE_OBJS) testsquaremaze.o
	$(CXX) -o $@ $^ goodmaze.o gooddsets.o

dsetstest.o: dsetstest.cpp dsetstest.h dsets.o
	$(CXX) -c $(CXX_OPTS) $<

squaremazetest.o: squaremazetest.cpp squaremazetest.h dsets.o maze.o EasyBMP.o
	$(CXX) -c $(CXX_OPTS) $<

dsets.o: dsets.cpp dsets.h
	$(CXX) -c $(CXX_OPTS) $<

maze.o: maze.cpp maze.h dsets.o
	$(CXX) -c $(CXX_OPTS) $<

EasyBMP.o: EasyBMP.cpp EasyBMP.h
	$(CXX) -c $(CXX_OPTS) $<

testall.o: testall.cpp squaremazetest.o dsetstest.o
	$(CXX) -c $(CXX_OPTS) $<

testdsets.o: testdsets.cpp dsetstest.o
	$(CXX) -c $(CXX_OPTS) $<

testsquaremaze.o: testsquaremaze.cpp squaremazetest.o
	$(CXX) -c $(CXX_OPTS) $<

# Grading Files

gooddsets.o: gooddsets.cpp gooddsets.h
	$(CXX) -c $(CXX_OPTS) $<

goodmaze.o: goodmaze.cpp goodmaze.h gooddsets.o
	$(CXX) -c $(CXX_OPTS) $<

