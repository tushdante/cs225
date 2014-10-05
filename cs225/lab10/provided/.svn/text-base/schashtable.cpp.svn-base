/*****************************************************
 *                                                   *
 *   schashtable.cpp                                 *   
 *   cs225 lab #11                                   *
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
   // Your code goes here.
   return false;
}

bool SCHashTable::remove(string searchKey)
{
   // Your code goes here.
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

