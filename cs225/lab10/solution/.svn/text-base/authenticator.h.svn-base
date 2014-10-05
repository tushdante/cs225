/*****************************************************
 *                                                   *
 *   authenticator.h                                 *   
 *   cs225 lab #11                                   *
 *                                                   *
 *   Made in Spring 2008 by Daniel Hoodin            * 
 *                                                   * 
 ****************************************************/

#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include <string>
#include "hashtable.h"
#include "hash.h"

using std::string;

class Authenticator
{
public:
   Authenticator(int numUsers, int mode, int hash, const string& filename);
   ~Authenticator();
   Authenticator(const Authenticator& other);
   void removeAllUsers();
   void showStructure();
   void showStatistics();
   bool removeUser(const string &un);
   bool addUser(const string& un, const string& pw);
   const Authenticator& operator=(const Authenticator& other);
   bool authenticate(const string& un, const string& pw);
   static const int SEPARATE_CHAINING = 0;
   static const int LINEAR_PROBING = 1;
   static const int SUMMING_COMPONENTS = 0;
   static const int CYCLIC_SHIFT = 1;
   static const int POLYNOMIAL = 2;
private:
   void copy(const Authenticator& other);
   void destruct();
   bool importFile(const string& filename);
   int mode;
   int hash;
   Hash* hashFunction;
   HashTable* passwords;
};

#endif

