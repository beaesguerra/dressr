#ifndef CLOSET_H
#define CLOSET_H

#include "clothingitem.h"
#include <vector>
#include <string>

#include <QJsonObject>

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
   void read(QJsonObject jObj);
   void write(QJsonObject & jObj);

private:
   vector <ClothingItem> m_items;
   vector <string> m_availableTypes;
};


#endif // CLOSET_H
