/*****************************************************
 *                                                   *
 *   tableentry.h                                    *   
 *   cs225 lab #11                                   *
 *                                                   *
 *   Made in Spring 2008 by Daniel Hoodin            * 
 *                                                   * 
 ****************************************************/

#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>

using std::string;

class TableEntry
{
public:
   static int hash(const string& str);
   TableEntry();
   virtual ~TableEntry();
   bool operator==(const TableEntry& other);
   TableEntry(const string& key, const string& value);
   string getKey() const;
   string getValue() const;
   void setKey(const string& key);
   void setValue(const string& value);
private:
   string key;
   string value;
};

#endif
