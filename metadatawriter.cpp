#include "metadatawriter.h"
#include <string>

// QT Includes
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QIODevice>
#include <QtGlobal>

MetaDataWriter::MetaDataWriter(Closet clst)
{
    QFile saveFile("dressr.json");
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

MetaDataWriter::~MetaDataWriter(Closet clst)
{
    QFile loadFile("dressr.json");
    QJsonObject top;

    if (!saveFile.open(QIODevice::ReadOnly))
    {
        qWarning("dressr.json could not be opened for reading!");
        return;
    }

    QByteArray loadData = loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(loadData));
    top = loadDoc.object();
    clst.read(top["Closet"]);
}
