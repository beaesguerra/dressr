#include "DressrUi.h"
#include <QApplication>

#include "closet.h"
#include "clothingitem.h"
#include "metadatawriter.h"
#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QLayout>
#include "ClosetUi.h"
#include <QStandardPaths>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DressrUi w;

    ClosetUi * closetUi = w.getClosetUi();
//    QString stdPath = QStandardPaths::standardLocations(QStandardPaths::HomeLocation)[0];
//    QString filename = QDir::currentPath().append("/shirt.jpg");

    Closet closet;
    QImage shirtImage2 = QImage("/storage/emulated/0/data/shirt.jpg");
    ClothingItem shirt2 = ClothingItem(shirtImage2, "shirt");
    closet.addItem(shirt2);
    closetUi->setTypes(closet.getTypes());

    for(int i = 0; i < 50; i++){
        closetUi->AddClothesToView(shirt2);
    }
    w.show();

    return a.exec();
}
