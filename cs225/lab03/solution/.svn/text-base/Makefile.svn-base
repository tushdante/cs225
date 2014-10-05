
TEST_BUILDING_OBJS = testbuilding.o apartment.o building.o 
TEST_MEMORY_LEAK_OBJS = testmemoryleak.o apartment.o building.o 
TEST_INVALID_READ_OBJS = testinvalidread.o apartment.o building.o 
TEST_INVALID_FREE_OBJS = testinvalidfree.o apartment.o building.o 

TEST_BUILDING_EXE = testbuilding
TEST_MEMORY_LEAK_EXE = testmemoryleak
TEST_INVALID_READ_EXE = testinvalidread
TEST_INVALID_FREE_EXE = testinvalidfree

COMPILER = g++
COMPILER_OPTS = -c -g -O0 -Wall
LINKER = g++
LINKER_OPTS = -o

# Linking

all : $(TEST_BUILDING_EXE) $(TEST_MEMORY_LEAK_EXE) $(TEST_INVALID_READ_EXE) $(TEST_INVALID_FREE_EXE)

$(TEST_BUILDING_EXE) : $(TEST_BUILDING_OBJS)
	$(LINKER) $(LINKER_OPTS) $(TEST_BUILDING_EXE) $(TEST_BUILDING_OBJS)

$(TEST_MEMORY_LEAK_EXE) : $(TEST_MEMORY_LEAK_OBJS)
	$(LINKER) $(LINKER_OPTS) $(TEST_MEMORY_LEAK_EXE) $(TEST_MEMORY_LEAK_OBJS)

$(TEST_INVALID_READ_EXE) : $(TEST_INVALID_READ_OBJS)
	$(LINKER) $(LINKER_OPTS) $(TEST_INVALID_READ_EXE) $(TEST_INVALID_READ_OBJS)

$(TEST_INVALID_FREE_EXE) : $(TEST_INVALID_FREE_OBJS)
	$(LINKER) $(LINKER_OPTS) $(TEST_INVALID_FREE_EXE) $(TEST_INVALID_FREE_OBJS)

# Compilation

testbuilding.o : testbuilding.cpp building.o
	$(COMPILER) $(COMPILER_OPTS) testbuilding.cpp

testmemoryleak.o : testmemoryleak.cpp building.o
	$(COMPILER) $(COMPILER_OPTS) testmemoryleak.cpp

testinvalidread.o : testinvalidread.cpp building.o
	$(COMPILER) $(COMPILER_OPTS) testinvalidread.cpp

testinvalidfree.o : testinvalidfree.cpp building.o
	$(COMPILER) $(COMPILER_OPTS) testinvalidfree.cpp
	
apartment.o : apartment.cpp apartment.h
	$(COMPILER) $(COMPILER_OPTS) apartment.cpp

building.o: building.cpp building.h apartment.o
	$(COMPILER) $(COMPILER_OPTS) building.cpp

clean : 
	rm -f *.o $(TEST_BUILDING_EXE) $(TEST_MEMORY_LEAK_EXE) $(TEST_INVALID_READ_EXE) $(TEST_INVALID_FREE_EXE)

