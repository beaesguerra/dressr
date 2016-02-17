#include "clothingitem.h"

unsigned int ClothingItem::m_itemCounter = 0;

ClothingItem::ClothingItem()
{

}

ClothingItem::ClothingItem(QImage image, string type)
{
    m_image = image;
    m_type = type;
    m_itemID = m_itemCounter;
    m_itemCounter++;
}

unsigned int ClothingItem::getItemID()
{
    return m_itemID;
}

string ClothingItem::getType()
{
    return m_type;
}

QImage ClothingItem::getImage()
{
    return m_image;
}

void ClothingItem::read(QJsonObject jObj)
{

}

void ClothingItem::write(QJsonObject &jObj)
{

}
