#include "clothingitem.h"

#include <QString>

int ClothingItem::m_itemCounter = 0;

ClothingItem::ClothingItem()
{
    m_itemID = -1;
}

ClothingItem::ClothingItem(QImage image, string type)
{
    m_image = image;
    m_type = type;
    m_itemID = m_itemCounter;
    m_itemCounter++;
}

int ClothingItem::getItemID()
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
    m_type = jObj["type"].toString().toStdString();
    m_image = QImage(jObj["img"].toString());
    m_itemID = jObj["id"].toInt();
}

void ClothingItem::write(QJsonObject &jObj)
{
    jObj["type"] = QString::fromStdString(m_type);
    jObj["id"] = (int) m_itemID;

    // TODO : Potentially make this more robust
    QString filename = QString::number(m_itemID).append(".png");
    m_image.save(filename);

    jObj["img"] = filename;
}
