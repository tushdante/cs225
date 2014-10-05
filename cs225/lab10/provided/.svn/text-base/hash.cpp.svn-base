/*****************************************************
 *                                                   *
 *   hash.cpp                                        *   
 *   cs225 lab #11                                   *
 *                                                   *
 *   Made in Spring 2008 by Daniel Hoodin            * 
 *                                                   * 
 ****************************************************/

#include "hash.h"
#include <iostream>
using namespace std;

int CyclicShiftHash::hash(const string& str)
{
   int h = 0;
   for(int i = 0; i < (int)str.length(); ++i)
   {
      h = (h << 5) | (h >> 27);
      h += str[i];
   }
   return h;
}

int SummingComponentsHash::hash(const string& str)
{
   int val = 0;
   for(int i = 0; i < (int)str.length(); ++i) 
      val += str[i];
   return val;
}

int PolynomialHash::hash(const string& str)
{
   int val = 0;
   int a = 7;
   int k = (int)str.length()-1;
   for(int i = 0; i < (int)str.length(); ++i)
      val += str[i]*(int)pow((double)a,(double)(k-i));
   return val;
}

