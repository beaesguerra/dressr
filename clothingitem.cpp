#include "clothingitem.h"


ClothingItem::ClothingItem(QImage image, string type)
{
    m_image = image;
    m_type = type;
    m_itemID = ClothingItem.m_itemCounter;
    ClothingItem.m_itemCounter++;
}
