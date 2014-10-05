/*****************************************************
 *                                                   *
 *   wordcount.cpp                                   *   
 *   cs225 lab #11                                   *
 *                                                   *
 *   Made in Spring 2008 by Daniel Hoodin            * 
 *                                                   * 
 ****************************************************/

#include <fstream>
#include <iostream>
#include "wordcount.h"
#include "schashtable.h"
#include "lphashtable.h"
#include "tableentry.h"

using std::ifstream;

WordCount::WordCount(int numUsers, int mode, int hash, const string& filename)
{
   this->mode = mode;
   this->hash = hash;

   if(hash == CYCLIC_SHIFT)
      hashFunction = new CyclicShiftHash();
   else if(hash == POLYNOMIAL)
      hashFunction = new PolynomialHash();
   else
      hashFunction = new SummingComponentsHash(); 
   if(mode == LINEAR_PROBING)
      wordcount = new LPHashTable(numUsers, hashFunction);
   else
      wordcount = new SCHashTable(numUsers, hashFunction);
   importFile(filename);
}

WordCount::~WordCount()
{
   destruct();
}

WordCount::WordCount(const WordCount& other)
{
   copy(other);
}

const WordCount& WordCount::operator=(const WordCount& other)
{
   if(this != &other)
   {
      destruct();
      copy(other);
   }
   return *this;
}

void WordCount::removeAllWords()
{
   wordcount->clear();
}

void WordCount::showStructure()
{
   wordcount->showStructure();
}

void WordCount::showStatistics()
{
   wordcount->showStatistics();
}

bool WordCount::removeWord(const string& word)
{
   return wordcount->remove(word);
}

bool WordCount::addWord(const string& word, const string& wc)
{
   return wordcount->insert(TableEntry(word,wc));
}

string WordCount::getWordCount(const string& word)
{
   TableEntry temp = wordcount->retrieve(word);
   if(temp.getKey() != word)
      return "0";
   else
      return temp.getValue();
}

void WordCount::copy(const WordCount& other)
{
   //TODO: implement this function
}

void WordCount::destruct()
{
   delete wordcount;
   delete hashFunction;
}

bool WordCount::importFile(const string& filename)
{
   ifstream wcFile(filename.c_str());
   string word;
   string wc;
   if(wcFile)
   {
      while(wcFile >> word >> wc)
      {
         wordcount->insert(TableEntry(word, wc));
      }
   }
   return true;
}

