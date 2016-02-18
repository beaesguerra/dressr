#include "clothingitem.h"

#include <QDir>
#include <QStandardPaths>
#include <QString>
#include <QApplication>
#include <QScreen>

int ClothingItem::m_itemCounter = 0;

ClothingItem::ClothingItem()
{
    m_itemID = -1;
    m_itemCounter++;
}

ClothingItem::ClothingItem(QImage image, string type)
{
    double screenWidth = QApplication::screens().at(0)->size().width();
    m_image = image;
    m_thumbnail = image.scaled(screenWidth/3.3 - 20, screenWidth/3.3 - 20, Qt::KeepAspectRatio);
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

QImage ClothingItem::getThumbnail()
{
    return m_thumbnail;
}

void ClothingItem::read(const QJsonObject &jObj)
{
    m_type = jObj["type"].toString().toStdString();
    m_image = QImage(jObj["img"].toString());
    m_itemID = jObj["id"].toInt();
}

void ClothingItem::write(QJsonObject &jObj)
{
    jObj["type"] = QString::fromStdString(m_type);
    jObj["id"] = (int) m_itemID;

    QString stdPath = QStandardPaths::standardLocations(QStandardPaths::AppConfigLocation)[0];
    QString filename = QDir(stdPath).absoluteFilePath(QString::number(m_itemID).append(".png").prepend("Dressr/"));
    m_image.save(filename);

    jObj["img"] = filename;
}
