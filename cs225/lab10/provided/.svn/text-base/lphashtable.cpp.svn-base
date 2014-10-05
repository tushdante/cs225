/*****************************************************
 *                                                   *
 *   lphashtable.cpp                                 *   
 *   cs225 lab #11                                   *
 *                                                   *
 *   Made in Spring 2008 by Daniel Hoodin            * 
 *                                                   * 
 ****************************************************/

#include "lphashtable.h"
#include <iostream>

using namespace std;

LPHashTable::LPHashTable(int initTableSize, Hash* hashFunction)
    : HashTable(initTableSize, hashFunction)
{
   // see initializer list
}

LPHashTable::~LPHashTable()
{
   // nothing to deallocate
}

bool LPHashTable::handleCollision(const TableEntry& newDataItem)
{
   // Your code goes here.
   return false;
}

bool LPHashTable::remove(string searchKey)
{
   // Your code goes here.
   return false;
}

TableEntry LPHashTable::retrieve(string searchKey)
{
   int index;
   for(int i = 0; i < tableSize; ++i)
   {
      index = probe(searchKey,i);
      if(!dataTable[index].empty() && dataTable[index].front().getKey() == searchKey)
         return dataTable[index].front();
   }
   return TableEntry();
}

int LPHashTable::probe(const string& key, int i)
{
   int hashCode = (hashFunction->hash(key) + i) % tableSize;
   if(hashCode < 0)
      hashCode += tableSize;
   return hashCode;
}

int LPHashTable::probe(const TableEntry& value, int i)
{
   return probe(value.getKey(),i);
}

