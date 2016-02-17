#ifndef CLOSET_H
#define CLOSET_H

#include "clothingitem.h"
#include <vector>
#include <string>

using namespace std;

class Closet
{
public:
   Closet();
   void addType(const string type);
   void removeType(const string type);
   ClothingItem getItem(unsigned int itemID);
   vector <ClothingItem> getAll();
   vector <ClothingItem> getAll(const string type);

private:
   vector <ClothingItem> m_items;
   vector <string> m_availableTypes;
};


#endif // CLOSET_H