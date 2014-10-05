/*****************************************************
 *                                                   *
 *   wordcount.h                                     *   
 *   cs225 lab #11                                   *
 *                                                   *
 *   Made in Spring 2008 by Daniel Hoodin            * 
 *                                                   * 
 ****************************************************/

#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <string>
#include "hashtable.h"
#include "hash.h"

using std::string;

class WordCount
{
public:
   WordCount(int numUsers, int mode, int hash, const string& filename);
   ~WordCount();
   WordCount(const WordCount& other);
   const WordCount& operator=(const WordCount& other);
   void showStructure();
   void showStatistics();
   string getWordCount(const string& word);
   bool addWord(const string& word, const string& wc);
   bool removeWord(const string& word);
   void removeAllWords();
   //bool authenticate(const string& un, const string& pw);
   static const int SEPARATE_CHAINING = 0;
   static const int LINEAR_PROBING = 1;
   static const int SUMMING_COMPONENTS = 0;
   static const int CYCLIC_SHIFT = 1;
   static const int POLYNOMIAL = 2;
private:
   void copy(const WordCount& other);
   void destruct();
   bool importFile(const string& filename);
   int mode;
   int hash;
   Hash* hashFunction;
   HashTable* wordcount;
};

#endif

