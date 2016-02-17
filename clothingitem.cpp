#include "clothingitem.h"

unsigned int ClothingItem::m_itemCounter = 0;

ClothingItem::ClothingItem(QImage image, string type)
{
    m_image = image;
    m_type = type;
    m_itemID = ClothingItem.m_itemCounter;
    ClothingItem.m_itemCounter++;
}

unsigned int ClothingItem::getItemID()
{
    return m_itemID;
}

string ClothingItem::getType()
{
    return m_type;
}

string ClothingItem::getImage()
{
    return m_image;
}
