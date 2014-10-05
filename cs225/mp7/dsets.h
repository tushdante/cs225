/********************************************************************
*
*  dsets.h --part of MP7
*  Header file for the dsets class
*	Declares functions used in dsets class
*  Date: December 1, 2010
*
********************************************************************/

#ifndef DSETS
#define DSETS

#include <vector>
#include <iostream>

using namespace std;


class DisjointSets
{
   public:


      void addelements(const int  Size);

      int find(int  node);

      void setunion(const int  node1, const int  node2);
      
      //void print();

      void clear();
      

   private:

      vector<int>  VectorTree;


};
#endif

