
#ifndef GOODDSETS_H
#define GOODDSETS_H

#include <vector>

class GoodDisjointSets
{
private:
   std::vector<int> links;

public:
   void addelements(int num);
   int find(int a);
   void setunion(int a, int b);
};

#endif

