CC = g++
CC_OPTS = -O0 -g
LINKER = g++

LC_TEST = charcount
LC_OBJS = letter_hash.o textfile.o char_counter.o charcount.o

ANAGRAM_TEST = anagramtest
ANAGRAM_OBJS = letter_hash.o textfile.o anagram_finder.o anagramtest.o

WC_TEST = wordcount
WC_OBJS = string_hash.o textfile.o word_counter.o wordcount.o

LP_HASH = lphashtable.cpp lphashtable.h hashtable.h
SC_HASH = schashtable.cpp schashtable.h hashtable.h

GENLOG = genlog

PARSER = lfparse
PARSE_OBJS = string_hash.o logfile_parser.o lfparse.o

all: $(LC_TEST) $(ANAGRAM_TEST) $(WC_TEST) $(GENLOG) $(PARSER)

$(LC_TEST) : $(LC_OBJS)
	$(LINKER) -o $(LC_TEST) $(LC_OBJS)

$(WC_TEST) : $(WC_OBJS)
	$(LINKER) -o $(WC_TEST) $(WC_OBJS)

$(ANAGRAM_TEST) : $(ANAGRAM_OBJS)
	$(LINKER) -o $(ANAGRAM_TEST) $(ANAGRAM_OBJS)

$(GENLOG) : logfile_generator.cpp
	$(CC) $(CC_OPTS) -o $(GENLOG) logfile_generator.cpp

$(PARSER) : $(PARSE_OBJS)
	$(LINKER) -o $(PARSER) $(PARSE_OBJS)

letter_hash.o : letter_hash.h letter_hash.cpp hash.h
	$(CC) $(CC_OPTS) -c letter_hash.cpp

anagram_finder.o : anagram_finder.h anagram_finder.cpp $(LP_HASH) $(SC_HASH)
	$(CC) $(CC_OPTS) -c anagram_finder.cpp

anagramtest.o : anagramtest.cpp anagram_finder.h
	$(CC) $(CC_OPTS) -c anagramtest.cpp

string_hash.o : string_hash.h string_hash.cpp hash.h
	$(CC) $(CC_OPTS) -c string_hash.cpp

word_counter.o : word_counter.h word_counter.cpp $(LP_HASH) $(SC_HASH)
	$(CC) $(CC_OPTS) -c word_counter.cpp

char_counter.o : char_counter.h char_counter.cpp $(LP_HASH) $(SC_HASH)
	$(CC) $(CC_OPTS) -c char_counter.cpp

charcount.o : charcount.cpp char_counter.h
	$(CC) $(CC_OPTS) -c charcount.cpp

wordcount.o : wordcount.cpp word_counter.h
	$(CC) $(CC_OPTS) -c wordcount.cpp

textfile.o : textfile.h textfile.cpp
	$(CC) $(CC_OPTS) -c textfile.cpp

lfparse.o : lfparse.cpp logfile_parser.h
	$(CC) $(CC_OPTS) -c lfparse.cpp

logfile_parser.o : $(LP_HASH) $(SC_HASH) logfile_parser.h logfile_parser.cpp
	$(CC) $(CC_OPTS) -c logfile_parser.cpp

clean:
	-rm -f *.o $(LC_TEST) $(LC_TEST).exe $(ANAGRAM_TEST) $(ANAGRAM_TEST).exe $(WC_TEST) $(WC_TEST).exe $(GENLOG) $(GENLOG).exe $(PARSER) $(PARSER).exe

tidy:
	-rm -f anagrams.txt
