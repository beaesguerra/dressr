#include "metadatawriter.h"
#include <string>

// QT Includes
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtGlobal>
#include <QStandardPaths>

MetaDataWriter::MetaDataWriter()
{

    QString stdPath = QStandardPaths::standardLocations(QStandardPaths::AppConfigLocation)[0];
//    QString stdPath = "/storage/emulated/0/data";
    m_filename = QDir(stdPath).absoluteFilePath("Dressr/dressr.json");

    QString path = QDir(stdPath).absoluteFilePath("Dressr");
    if (!QDir(path).exists())
        QDir(path).mkpath(".");
}

void MetaDataWriter::save()
{
    QFile saveFile(m_filename);
    QJsonObject top, jsonClst;

    if (!saveFile.open(QIODevice::WriteOnly))
    {
        qWarning("dressr.json could not be opened for writing!");
        return;
    }

    m_closet->write(jsonClst);

    top["Closet"] = jsonClst;

    QJsonDocument saveDoc(top);
    saveFile.write(saveDoc.toJson());
}

void MetaDataWriter::load(Closet &clst)
{
    m_closet = &clst;
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
