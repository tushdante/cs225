/*****************************************************
 *                                                   *
 *   authenticator.cpp                               *   
 *   cs225 lab #11                                   *
 *                                                   *
 *   Made in Spring 2008 by Daniel Hoodin            * 
 *                                                   * 
 ****************************************************/

#include <fstream>
#include "authenticator.h"
#include "schashtable.h"
#include "lphashtable.h"
#include "tableentry.h"

using std::ifstream;

Authenticator::Authenticator(int numUsers, int mode, int hash, const string& filename)
{
   this->mode = mode;
   this->hash = hash;
   if(hash == CYCLIC_SHIFT)
      hashFunction = new CyclicShiftHash();
   else if(hash == POLYNOMIAL)
      hashFunction = new PolynomialHash();
   else
      hashFunction = new SummingComponentsHash(); 

   if(mode == LINEAR_PROBING)
      passwords = new LPHashTable(numUsers, hashFunction);
   else
      passwords = new SCHashTable(numUsers, hashFunction);
   importFile(filename);
}

Authenticator::~Authenticator()
{
   destruct();
}

Authenticator::Authenticator(const Authenticator& other)
{
   copy(other);
}

const Authenticator& Authenticator::operator=(const Authenticator& other)
{
   if(this != &other)
   {
      destruct();
      copy(other);
   }
   return *this;
}

void Authenticator::removeAllUsers()
{
   passwords->clear();
}

void Authenticator::showStructure()
{
   passwords->showStructure();
}

void Authenticator::showStatistics()
{
   passwords->showStatistics();
}

bool Authenticator::removeUser(const string &un)
{
   return passwords->remove(un);
}

bool Authenticator::addUser(const string& un, const string& pw)
{
   return passwords->insert(TableEntry(un,pw));
}

bool Authenticator::authenticate(const string& un, const string& pw)
{
   TableEntry temp = passwords->retrieve(un);
   if(temp.getKey() != un)
      return false;
   else
      return pw == temp.getValue();
}

void Authenticator::copy(const Authenticator& other)
{
   //TODO: implement this function
}

void Authenticator::destruct()
{
   delete passwords;
   delete hashFunction;
}

bool Authenticator::importFile(const string& filename)
{
   ifstream passFile(filename.c_str());
   string username;
   string password;
   if(passFile)
   {
      while(passFile >> username >> password)
      {
         passwords->insert(TableEntry(username, password));
      }
   }
   return true;
}

