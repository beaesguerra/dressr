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
#include "PickUi.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PickUi * pickUi = new PickUi();
    Closet * closet = new Closet();
    ClosetUi * closetUi = new ClosetUi(closet);
    DressrUi * w = new DressrUi(pickUi, closetUi);

//    QString stdPath = QStandardPaths::standardLocations(QStandardPaths::HomeLocation)[0];
//    QString filename = QDir::currentPath().append("/shirt.jpg");


    for (int i = 0; i < 10; i++)
    {
        QImage shirtImage1 = QImage("/storage/emulated/0/data/testshirt.jpg");
        ClothingItem shirt1 = ClothingItem(shirtImage1, "Top");

        QImage shirtImage2 = QImage("/storage/emulated/0/data/testpants.jpg");
        ClothingItem shirt2 = ClothingItem(shirtImage2, "Bottom");

        QImage shirtImage3 = QImage("/storage/emulated/0/data/shirt.png");
        ClothingItem shirt3 = ClothingItem(shirtImage3, "Top");

        closet->addItem(shirt1);
        closet->addItem(shirt2);
        closet->addItem(shirt3);
    }
    closetUi->SetTypes(closet->getTypes());

    //for(int i = 0; i < 50; i++){
    //    closetUi->AddClothesToView(shirt2);
    //}
    w->show();

    return a.exec();
}
