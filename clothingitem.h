#ifndef CLOTHINGITEM_H
#define CLOTHINGITEM_H

#include <QImage>
#include <string>

class ClothingItem
{
public:
   ClothingItem(QImage image, string type);

private:
   QImage m_image;
   string m_type;
   unsigned int m_itemID;
   static unsigned int m_itemCounter = 0;
};

#endif // CLOTHINGITEM_H
