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

    ClosetUi * closetUi= w.getClosetUi();
    QString stdPath = QStandardPaths::standardLocations(QStandardPaths::HomeLocation)[0];
    QString filename = QDir::currentPath().append("/shirt.jpg");

    QImage shirtImage = QImage(filename);
    ClothingItem shirt = ClothingItem(shirtImage, "shirt");

    Closet closet;
    closet.addItem(shirt);


    QImage shirtImage2 = QImage("/home/bea/Documents/dressr/Resources/shirt.png");
    ClothingItem shirt2 = ClothingItem(shirtImage2, "shirt");
    closetUi->AddClothesToView(shirt2);

    closetUi->AddClothesToView(shirt);


    w.show();

    return a.exec();
}
