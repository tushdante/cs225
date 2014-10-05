
TEST_ROSE_OBJS =  EasyBMP.o rose.o flower.o garden.o gardenHelper.o testrose.o
TEST_LILAC_OBJS = EasyBMP.o lilac.o rose.o flower.o garden.o gardenHelper.o testlilac.o
TEST_GARDEN_OBJS = EasyBMP.o rose.o lilac.o carnation.o flower.o garden.o gardenHelper.o testgarden.o

TEST_ROSE_EXE = testrose
TEST_LILAC_EXE = testlilac
TEST_GARDEN_EXE = testgarden

COMPILER = g++
COMPILER_OPTS = -c -g -O0 -Wall
LINKER = g++
LINKER_OPTS = -o

# Linking

all : $(TEST_ROSE_EXE) $(TEST_LILAC_EXE) $(TEST_GARDEN_EXE)

$(TEST_ROSE_EXE) : $(TEST_ROSE_OBJS)
	$(LINKER) $(LINKER_OPTS) $(TEST_ROSE_EXE) $(TEST_ROSE_OBJS)

$(TEST_LILAC_EXE) : $(TEST_LILAC_OBJS)
	$(LINKER) $(LINKER_OPTS) $(TEST_LILAC_EXE) $(TEST_LILAC_OBJS)

$(TEST_GARDEN_EXE) : $(TEST_GARDEN_OBJS)
	$(LINKER) $(LINKER_OPTS) $(TEST_GARDEN_EXE) $(TEST_GARDEN_OBJS)

# Compilation

EasyBMP.o : EasyBMP.cpp
	$(COMPILER) $(COMPILER_OPTS) EasyBMP.cpp

rose.o : flower.o gardenHelper.o rose.cpp
	$(COMPILER) $(COMPILER_OPTS) rose.cpp

flower.o : EasyBMP.o flower.cpp
	$(COMPILER) $(COMPILER_OPTS) flower.cpp

garden.o : EasyBMP.o flower.o garden.cpp
	$(COMPILER) $(COMPILER_OPTS) garden.cpp

gardenHelper.o : EasyBMP.o gardenHelper.cpp
	$(COMPILER) $(COMPILER_OPTS) gardenHelper.cpp

lilac.o : flower.o gardenHelper.o lilac.cpp
	$(COMPILER) $(COMPILER_OPTS) lilac.cpp

carnation.o : flower.o gardenHelper.o carnation.cpp
	$(COMPILER) $(COMPILER_OPTS) carnation.cpp

tesetrose.o : garden.o rose.o testrose.cpp
	$(COMPILER) $(COMPILER_OPTS) testrose.cpp

testlilac.o : garden.o lilac.o testlilac.cpp
	$(COMPILER) $(COMPILER_OPTS) testlilac.cpp

testgarden.o : garden.o lilac.o rose.o carnation.o testgarden.cpp
	$(COMPILER) $(COMPILER_OPTS) testgarden.cpp

clean : 
	rm -f *.o $(TEST_ROSE_EXE) $(TEST_LILAC_EXE) $(TEST_GARDEN_EXE)

