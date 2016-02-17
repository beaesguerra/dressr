#ifndef CLOTHINGITEM_H
#define CLOTHINGITEM_H

#include <QImage>
#include <string>

using namespace std;

class ClothingItem
{
public:
   ClothingItem(QImage image, string type);
   unsigned int getItemID();
   string getType();
   string getImage();

private:
   QImage m_image;
   string m_type;
   unsigned int m_itemID;
   static unsigned int m_itemCounter = 0;
};

#endif // CLOTHINGITEM_H
