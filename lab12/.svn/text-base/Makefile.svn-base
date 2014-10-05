# Makefile for Lab 12, CS 225 Spring 2011

CC = g++
CC_OPTS = -O0 -g -c
LINKER = g++

GRAPH_DEMO = graphdemo
GRAPH_OBJS = string_hash.o graph.o graph_demo.o

KRUSKAL_TEST = kruskaltest
KRUSKAL_OBJS = string_hash.o graph.o kruskal.o kruskal_test.o dsets.o

WEIGHT_TEST = minweighttest
WEIGHT_OBJS = string_hash.o graph.o minweight.o minweight_test.o

PATH_TEST = minpathtest
PATH_OBJS = string_hash.o graph.o minpath.o minpath_test.o

SC_HASH = libhashtable/schashtable.cpp libhashtable/schashtable.h libhashtable/sciterator.cpp libhashtable/hashtable.h
DSETS   = libdsets/dsets.h libdsets/dsets.cpp

all: $(GRAPH_DEMO) $(KRUSKAL_TEST) $(WEIGHT_TEST) $(PATH_TEST)

$(GRAPH_DEMO) : $(GRAPH_OBJS)
	$(LINKER) -o $(GRAPH_DEMO) $(GRAPH_OBJS)
	
$(KRUSKAL_TEST) : $(KRUSKAL_OBJS)
	$(LINKER) -o $(KRUSKAL_TEST) $(KRUSKAL_OBJS)
    
$(WEIGHT_TEST) : $(WEIGHT_OBJS)
	$(LINKER) -o $(WEIGHT_TEST) $(WEIGHT_OBJS)
	
$(PATH_TEST) : $(PATH_OBJS)
	$(LINKER) -o $(PATH_TEST) $(PATH_OBJS)

graph_demo.o : graph_demo.cpp graph.h example_graphs.cpp
	$(CC) $(CC_OPTS) graph_demo.cpp
	
kruskal_test.o : kruskal_test.cpp kruskal.h
	$(CC) $(CC_OPTS) kruskal_test.cpp
    
minweight_test.o : minweight_test.cpp minweight.h
	$(CC) $(CC_OPTS) minweight_test.cpp

minpath_test.o : minpath_test.cpp minpath.h
	$(CC) $(CC_OPTS) minpath_test.cpp

graph.o : graph.h graph.cpp $(SC_HASH)
	$(CC) $(CC_OPTS) graph.cpp
	
kruskal.o : kruskal.cpp kruskal.h graph.h $(DSETS)
	$(CC) $(CC_OPTS) kruskal.cpp
	
dsets.o : libdsets/dsets.cpp libdsets/dsets.h
	$(CC) $(CC_OPTS) libdsets/dsets.cpp
	
minweight.o : minweight.cpp minweight.h graph.h
	$(CC) $(CC_OPTS) minweight.cpp
	
minpath.o : minpath.cpp minpath.h graph.h
	$(CC) $(CC_OPTS) minpath.cpp
	
string_hash.o : libhashtable/string_hash.h libhashtable/string_hash.cpp libhashtable/hash.h
	$(CC) $(CC_OPTS) libhashtable/string_hash.cpp

clean:
	-rm -f *.o $(GRAPH_DEMO) $(KRUSKAL_TEST) $(WEIGHT_TEST) $(PATH_TEST) libhashtable/*.gch libdsets/*.gch

tidy:
	-rm -f images/*.png
