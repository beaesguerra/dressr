#ifndef CLOSET_H
#define CLOSET_H

#include "clothingitem.h"
#include <vector>
#include <string>
#include <QWidget>

#include <QJsonObject>

using namespace std;

class Closet : public QWidget
{
   Q_OBJECT
public:
   Closet();
   void addItem(const ClothingItem item);
   void addType(const string type);
   void removeType(const string type);
   ClothingItem getItem(int itemID);
   vector <ClothingItem> getAll();
   vector <string> getTypes();
   vector <ClothingItem> getAll(const string type);
   void read(const QJsonObject &jObj);
   void write(QJsonObject & jObj);

public slots:
   void removeItem(int itemID);

private:
   vector <ClothingItem> m_items;
   vector <string> m_availableTypes;
};


#endif // CLOSET_H
