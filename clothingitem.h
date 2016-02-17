#ifndef CLOTHINGITEM_H
#define CLOTHINGITEM_H

#include <QImage>
#include <string>

#include <QJsonObject>

using namespace std;

class ClothingItem
{
public:
   ClothingItem();
   ClothingItem(QImage image, string type);
   unsigned int getItemID();
   string getType();
   QImage getImage();
   void read(QJsonObject jObj);
   void write(QJsonObject &jObj);

private:
   QImage m_image;
   string m_type;
   unsigned int m_itemID;
   static unsigned int m_itemCounter;
};

#endif // CLOTHINGITEM_H
