
EXENAME = hashtable
TESTNAME = testhashtable

CXX = g++
CXX_FLAGS = -g -O0 -Wall
OBJS = main.o authenticator.o wordcount.o tableentry.o schashtable.o lphashtable.o hashtable.o hash.o
TESTOBJS = testhashtable.o authenticator.o tableentry.o schashtable.o lphashtable.o hashtable.o hash.o validator.o

$(EXENAME) : $(OBJS)
	$(CXX) -o $@ $^

$(TESTNAME) : $(TESTOBJS)
	$(CXX) -o $@ $^

main.o: main.cpp authenticator.o wordcount.o
	$(CXX) -c $(CXX_FLAGS) $<

testhashtable.o: testhashtable.cpp authenticator.o validator.o
	$(CXX) -c $(CXX_FLAGS) $<

hash.o: hash.cpp hash.h
	$(CXX) -c $(CXX_FLAGS) $<

wordcount.o: wordcount.cpp wordcount.h tableentry.o lphashtable.o schashtable.o hashtable.o
	$(CXX) -c $(CXX_FLAGS) $<

authenticator.o: authenticator.cpp authenticator.h tableentry.o lphashtable.o schashtable.o hashtable.o
	$(CXX) -c $(CXX_FLAGS) $<

hashtable.o: hashtable.cpp hashtable.h
	$(CXX) -c $(CXX_FLAGS) $<

schashtable.o: schashtable.cpp schashtable.h hashtable.o
	$(CXX) -c $(CXX_FLAGS) $<

lphashtable.o: lphashtable.cpp lphashtable.h hashtable.o
	$(CXX) -c $(CXX_FLAGS) $<

tableentry.o: tableentry.cpp tableentry.h
	$(CXX) -c $(CXX_FLAGS) $<

validator.o: validator.cpp validator.h
	$(CXX) -c $(CXX_FLAGS) $<

clean:
	-rm *.o $(EXENAME) $(TESTNAME) 2> /dev/null

