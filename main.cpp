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

    QImage shirtImage2 = QImage("/storage/emulated/0/data/shirt.jpg");
    ClothingItem shirt2 = ClothingItem(shirtImage2, "Top");
    closet->addItem(shirt2);

    for(int i = 0; i < 50; i++){
        closetUi->AddClothesToView(shirt2);
    }
    w->show();

    return a.exec();
}
