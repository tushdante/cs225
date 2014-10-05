/*****************************************************
 *                                                   *
 *   hash.h                                          *   
 *   cs225 lab #11                                   *
 *                                                   *
 *   Made in Spring 2008 by Daniel Hoodin            * 
 *                                                   * 
 ****************************************************/

#ifndef HASH_H
#define HASH_H

#include <string>
using std::string;

class Hash
{
public:
   virtual int hash(const string& str) = 0;
   virtual ~Hash()
   {
      // nothing to deallocate
   }
};

#endif

#ifndef CYCLICSHIFTHASH_H
#define CYCLICSHIFTHASH_H

#include <string>
using std::string;

class CyclicShiftHash : public Hash
{
public:
   virtual int hash(const string& str);
};

#endif

#ifndef SUMMINGCOMPONENTSHASH_H
#define SUMMINGCOMPONENTSHASH_H

#include <string>
using std::string;

class SummingComponentsHash : public Hash
{
public:
   virtual int hash(const string& str);
};

#endif

#ifndef POLYNOMIALHASH_H
#define POLYNOMIALHASH_H

#include <string>
#include <cmath>
using std::string;

class PolynomialHash : public Hash
{
public:
   virtual int hash(const string& str);
};

#endif

