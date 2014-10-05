/*****************************************************
 *                                                   *
 *   schashtable.cpp                                 *   
 *   cs225 lab #10                                   *
 *                                                   *
 *   Made in Spring 2008 by Daniel Hoodin            * 
 *                                                   * 
 ****************************************************/

#include "schashtable.h"
#include <iostream>

using namespace std;

SCHashTable::SCHashTable(int initTableSize, Hash* hashFunction)
    : HashTable(initTableSize, hashFunction)
{
   // see initializer list
}

SCHashTable::~SCHashTable()
{
   // nothing to destruct
}

bool SCHashTable::handleCollision(const TableEntry& newDataItem)
{
   int index = hash(newDataItem);
   for(list<TableEntry>::iterator it = dataTable[index].begin(); it != dataTable[index].end(); it++)
   {
      if(it->getKey() == newDataItem.getKey())
      {
         it->setValue(newDataItem.getValue());
         return true;
      }
   }
   dataTable[index].push_back(newDataItem);
   ++numEntries;
   return true;
}

bool SCHashTable::remove(string searchKey)
{
   int index = hash(searchKey);

   if(dataTable[index].empty())
       return false;

   for(list<TableEntry>::iterator it = dataTable[index].begin(); it != dataTable[index].end(); it++)
   {
      if(it->getKey() == searchKey)
      {
         dataTable[index].remove(*it);
         --numEntries;
         if(dataTable[index].empty())
            --numLists;
         return true;
      }
   }
   return false;
}

TableEntry SCHashTable::retrieve(string searchKey)
{
   int index = hash(searchKey)%tableSize;

   if(dataTable[index].empty())
      return TableEntry();
   
   for(list<TableEntry>::iterator it = dataTable[index].begin(); it != dataTable[index].end(); it++)
   {
      if(it->getKey() == searchKey)
      {
         return *it;
      }
   }

   return TableEntry();
}

