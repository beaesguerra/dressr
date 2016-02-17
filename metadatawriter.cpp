#include "metadatawriter.h"
#include <string>

#include <QDebug>
// QT Includes
#include <QDir>
#include <QFile>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtGlobal>
#include <QStandardPaths>

MetaDataWriter::MetaDataWriter()
{

    QString stdPath = QStandardPaths::standardLocations(QStandardPaths::HomeLocation)[0];
    m_filename = QDir(stdPath).absoluteFilePath("Dressr/dresser.json");

    qDebug() << m_filename;
    QString path = QDir(stdPath).absoluteFilePath("Dressr");
    if (!QDir(path).exists())
        QDir(path).mkpath(".");
}

void MetaDataWriter::save(Closet &clst)
{
    QFile saveFile(m_filename);
    QJsonObject top, jsonClst;

    if (!saveFile.open(QIODevice::WriteOnly))
    {
        qWarning("dressr.json could not be opened for writing!");
        return;
    }

    clst.write(jsonClst);

    top["Closet"] = jsonClst;

    QJsonDocument saveDoc(top);
    saveFile.write(saveDoc.toJson());
}

void MetaDataWriter::load(Closet &clst)
{
    QFile loadFile(m_filename);
    QJsonObject top;

    if (!loadFile.open(QIODevice::ReadOnly))
    {
        qWarning("dressr.json could not be opened for reading!");
        return;
    }

    QByteArray loadData = loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(loadData));
    top = loadDoc.object();
    clst.read(top["Closet"].toObject());
}
