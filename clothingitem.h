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
   int getItemID(); // itemID of -1 for empty clothing item objects (initialized in default constructor)
   string getType();
   QImage getImage();
   void read(const QJsonObject &jObj);
   void write(QJsonObject &jObj);
   void setImage(QImage image);
   void setThumbnail(QImage image);

   QImage getThumbnail();

private:
   QImage m_image;
   QImage m_thumbnail;
   string m_type;
   int m_itemID;
   static int m_itemCounter;
};

#endif // CLOTHINGITEM_H
