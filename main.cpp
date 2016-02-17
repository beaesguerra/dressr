#include "DressrUi.h"
#include <QApplication>

#include <QDebug>


#include "closet.h"
#include "clothingitem.h"
#include "metadatawriter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DressrUi w;
    w.show();

    MetaDataWriter mdWriter;
    Closet closet;
    mdWriter.load(closet);
    ClothingItem item(QImage(), "Bottom");
    closet.addItem(item);

    qDebug() << QString::number(closet.getAll().size());
    for (int i = 0; i < closet.getAll().size(); i++)
        qDebug() << QString::fromStdString(closet.getItem(i).getType());
    mdWriter.save(closet);

    return a.exec();
}
