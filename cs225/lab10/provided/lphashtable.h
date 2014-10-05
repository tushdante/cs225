/*****************************************************
 *                                                   *
 *   lphashtable.cpp                                 *   
 *   cs225 lab #11                                   *
 *                                                   *
 *   Made in Spring 2008 by Daniel Hoodin            * 
 *                                                   * 
 ****************************************************/

#ifndef LPHASHTABLE_H
#define LPHASHTABLE_H

#include "hashtable.h"
#include "tableentry.h"
#include <list>

using std::list;

class LPHashTable : public HashTable
{
public:
   LPHashTable(int initTableSize, Hash* hashFunction);
   ~LPHashTable();
   bool remove(string searchKey);
   TableEntry retrieve(string searchKey);
   bool handleCollision(const TableEntry& newDataItem);
private:
   int probe(const string& key, int i);
   int probe(const TableEntry& value, int i);
};

#endif

