/*****************************************************
 *                                                   *
 *   tableentry.cpp                                  *   
 *   cs225 lab #11                                   *
 *                                                   *
 *   Made in Spring 2008 by Daniel Hoodin            * 
 *                                                   * 
 ****************************************************/

#include "tableentry.h"

TableEntry::TableEntry()
{
   key = "";
   value = "";
}

TableEntry::~TableEntry()
{
   // nothing to deallocate
}

TableEntry::TableEntry(const string& key, const string& value)
{
   this->key = key;
   this->value = value;
}

bool TableEntry::operator==(const TableEntry& other)
{
   return key == other.key && value == other.value;
}

string TableEntry::getKey() const
{
   return key;
}

string TableEntry::getValue() const
{
   return value;
}

void TableEntry::setKey(const string& key)
{
   this->key = key;
}

void TableEntry::setValue(const string& value)
{
   this->value = value;
}

/*int TableEntry::hash(const string& str)
{
   int val = 0;
   for (unsigned int i=0; i<str.length(); i++) 
      val += str[i];
   return val;
}*/

