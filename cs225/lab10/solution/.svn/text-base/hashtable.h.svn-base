/*****************************************************
 *                                                   *
 *   hashtable.h                                     *   
 *   cs225 lab #11                                   *
 *                                                   *
 *   Made in Spring 2008 by Daniel Hoodin            * 
 *                                                   * 
 ****************************************************/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include "tableentry.h"
#include "hash.h"

using std::list;

class HashTable
{
public:
   HashTable(int initTableSize, Hash* hashFunction);
   virtual ~HashTable();
   virtual const HashTable& operator=(const HashTable& other);

   virtual bool insert(const TableEntry &newDataItem);
   virtual bool handleCollision(const TableEntry& newDataItem) = 0;
   virtual bool remove(string searchKey) = 0;
   virtual TableEntry retrieve(string searchKey) = 0;
   virtual void clear();
   virtual bool isEmpty() const;
   virtual void showStructure() const;
   virtual void showStatistics() const;

protected:
   int hash(const string& key);
   int hash(const TableEntry& value);
   void copy(const HashTable& other);
   void destruct();
   int numLists;
   int numEntries;
   int numCollisions;
   int tableSize;
   Hash* hashFunction;
   list<TableEntry>* dataTable;
};

#endif

