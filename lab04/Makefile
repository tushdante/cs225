# Copyright 2011 University of Illinois at Urbana-Champaign
# CS 225 Lab 04 C++ Object Oriented Programming
# Authors:
#   Simon Krueger <skruege2@illinois.edu>

CXX = g++
CXXFLAGS = -g -O0
CPPFLAGS =
COMPILE.cpp = $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c
LDFLAGS =
LDLIBS =
LINK.cpp = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)

EXEC = lab4
OBJS = main.o EasyBMP.o vector2.o shape.o rectangle.o line.o

TEST_PURE_VIRTUAL = test_pure_virtual
TEST_PURE_VIRTUAL_OBJS = test_pure_virtual.o truck.o EasyBMP.o vector2.o \
                         shape.o circle.o rectangle.o line.o
TEST_VIRTUAL = test_virtual
TEST_VIRTUAL_OBJS = test_virtual.o shape.o rectangle.o vector2.o EasyBMP.o \
                    line.o
TEST_DESTRUCTOR = test_destructor
TEST_DESTRUCTOR_OBJS = test_destructor.o EasyBMP.o triangle.o shape.o \
                       vector2.o line.o
TEST_SLICING = test_slicing
TEST_SLICING_OBJS = test_slicing.o EasyBMP.o vector2.o flower.o shape.o \
                    triangle.o rectangle.o circle.o line.o
TEST_CONSTRUCTOR = test_constructor
TEST_CONSTRUCTOR_OBJS = test_constructor.o circle.o shape.o EasyBMP.o \
                        vector2.o line.o

EXECS = $(EXEC) $(TEST_CONSTRUCTOR) $(TEST_VIRTUAL) \
        $(TEST_DESTRUCTOR) $(TEST_SLICING) $(TEST_BASE_CONSTRUCTOR) \
        $(TEST_PURE_VIRTUAL)

.PHONY: all
all: $(EXECS)

$(EXEC): main.o $(OBJS)
	$(LINK.cpp) $^ $(LDLIBS) -o $@

$(TEST_PURE_VIRTUAL): $(TEST_PURE_VIRTUAL_OBJS)
	$(LINK.cpp) $^ $(LDLIBS) -o $@

$(TEST_VIRTUAL): $(TEST_VIRTUAL_OBJS)
	$(LINK.cpp) $^ $(LDLIBS) -o $@

$(TEST_DESTRUCTOR): $(TEST_DESTRUCTOR_OBJS)
	$(LINK.cpp) $^ $(LDLIBS) -o $@

$(TEST_CONSTRUCTOR): $(TEST_CONSTRUCTOR_OBJS)
	$(LINK.cpp) $^ $(LDLIBS) -o $@

$(TEST_SLICING): $(TEST_SLICING_OBJS)
	$(LINK.cpp) $^ $(LDLIBS) -o $@

main.o: main.cpp rectangle.h color.h vector2.h \
        drawable.h shape.h EasyBMP.h
	 $(COMPILE.cpp) $<

circle.h: shape.h
	touch $@
circle.o: circle.cpp circle.h
	$(COMPILE.cpp) $<

drawable.h: EasyBMP.h
	touch $@

EasyBMP.h: EasyBMP_BMP.h EasyBMP_DataStructures.h EasyBMP_VariousBMPutilities.h
	touch $@
EasyBMP.o: EasyBMP.cpp EasyBMP.h
	$(COMPILE.cpp) $<

flower.h: shape.h
	touch $@
flower.o: flower.cpp flower.h color.h
	$(COMPILE.cpp) $<

line.h: drawable.h vector2.h
	touch $@
line.o: line.cpp line.h
	$(COMPILE.cpp) $<

rectangle.h: shape.h
	touch $@
rectangle.o: rectangle.cpp rectangle.h
	$(COMPILE.cpp) $<

shape.h: drawable.h vector2.h
	touch $@
shape.o: shape.cpp shape.h color.h
	$(COMPILE.cpp) $<

test_constructor.o: test_constructor.cpp circle.h vector2.h shape.h \
                    color.h drawable.h EasyBMP.h
	$(COMPILE.cpp) $<

test_destructor.o: test_destructor.cpp EasyBMP.h triangle.h vector2.h \
                   shape.h
	$(COMPILE.cpp) $<

test_slicing.o: test_slicing.cpp EasyBMP.h flower.h vector2.h
	$(COMPILE.cpp) $<

test_pure_virtual.o: test_pure_virtual.cpp truck.h vector2.h \
                     drawable.h EasyBMP.h
	$(COMPILE.cpp) $<

test_virtual.o: test_virtual.cpp rectangle.h shape.h vector2.h color.h \
                drawable.h EasyBMP.h
	$(COMPILE.cpp) $<

triangle.h: shape.h
	touch $@
triangle.o: triangle.cpp triangle.h line.h
	$(COMPILE.cpp) $<

truck.h: circle.h drawable.h rectangle.h vector2.h
	touch $@
truck.o: truck.cpp truck.h color.h
	$(COMPILE.cpp) $<

vector2.o: vector2.cpp vector2.h
	$(COMPILE.cpp) $<

.PHONY: clean
clean: 
	rm -f *.o $(EXECS)

