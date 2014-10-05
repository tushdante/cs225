/*****************************************************
 *                                                   *
 *   schashtable.h                                   *   
 *   cs225 lab #11                                   *
 *                                                   *
 *   Made in Spring 2008 by Daniel Hoodin            * 
 *                                                   * 
 ****************************************************/

#ifndef SCHASHTABLE_H
#define SCHASHTABLE_H

#include "hashtable.h"
#include "tableentry.h"
#include <list>

using std::list;

class SCHashTable : public HashTable
{
public:
   SCHashTable(int initTableSize, Hash* hashFunction);
   ~SCHashTable();
   bool remove(string searchKey);
   TableEntry retrieve(string searchKey);
   bool handleCollision(const TableEntry& newDataItem);
};

#endif

