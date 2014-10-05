/*****************************************************
 *                                                   *
 *   hashtable.cpp                                   *   
 *   cs225 lab #11                                   *
 *                                                   *
 *   Made in Spring 2008 by Daniel Hoodin            * 
 *                                                   * 
 ****************************************************/

#include "hashtable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int initTableSize, Hash* hashFunction)
    : tableSize(initTableSize)
{
   numEntries = 0;
   numLists = 0;
   numCollisions = 0;
   this->hashFunction = hashFunction;
   dataTable = new list<TableEntry>[tableSize];
}

HashTable::~HashTable()
{
   destruct();
}

const HashTable& HashTable::operator=(const HashTable& other)
{
   if(this != &other)
   {
      destruct();
      copy(other);
   }
   return *this;
}

void HashTable::copy(const HashTable& other)
{
   /*tableSize = other.tableSize;
   dataTable = new list<TableEntry>[tableSize];
   for(int i = 0; i < tableSize; ++i)
      dataTable[i] = new list<TableEntry>(other.dataTable[i]);*/
}

void HashTable::destruct()
{
    delete[] dataTable;
}

int HashTable::hash(const string& key)
{
   int hashCode = hashFunction->hash(key) % tableSize;
   if(hashCode < 0)
      hashCode += tableSize;
   return hashCode;
}

int HashTable::hash(const TableEntry& value)
{
   return hash(value.getKey());
}

void HashTable::showStatistics() const
{
   double loadFactor = ((double)numLists)/tableSize;
   cout << "HashTable Statistics:" << endl;
   cout << "     Table Size = " << tableSize << endl;
   cout << "   # of Entries = " << numEntries << endl;
   cout << "     # of Lists = " << numLists << endl;
   cout << "    Load Factor = " << loadFactor << endl;
   cout << "# of Collisions = " << numCollisions << endl;
   cout << endl;
}

bool HashTable::insert(const TableEntry& newDataItem)
{
   int index = hash(newDataItem);
   if (dataTable[index].empty())
   {
      ++numLists;
      ++numEntries;
      dataTable[index].push_back(newDataItem);
      return true;
   }
   else if(dataTable[index].front().getKey() == newDataItem.getKey())
   {
      dataTable[index].pop_front();
      dataTable[index].push_front(newDataItem);
      return true; 
   }
   ++numCollisions;
   return handleCollision(newDataItem);
}

void HashTable::clear ()
{
    for (int i=0; i<tableSize; i++)
    {
        dataTable[i].clear();
    }
    numEntries = 0;
    numLists = 0;
}

bool HashTable::isEmpty () const
{
   for(int i = 0; i < tableSize; i++)
   {
      if(!dataTable[i].empty())
         return false;
   }
   return true;
}

void HashTable::showStructure() const
{
   cout << "The Hash Table has the following entries" <<endl;
   for ( int i=0; i<tableSize; i++ )
   {
      cout << i << ": ";
      if(dataTable[i].empty())
         cout << "_";
      else
      {       
         for(list<TableEntry>::iterator it = dataTable[i].begin(); it != dataTable[i].end(); it++)
         {
            cout << it->getKey() << " ";
         }
      }
      cout << endl << endl;
   }
}

