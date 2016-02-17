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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DressrUi w;

    ClosetUi * closetUi= w.getClosetUi();
    QImage shirtImage = QImage("/home/bea/Documents/dressr/shirt.jpg");
    ClothingItem shirt = ClothingItem(shirtImage, "shirt");
    Closet closet;
    closet.addItem(shirt);

    closetUi->AddClothes(shirt);
    /*
    QPixmap* clothingImage = new QPixmap();
    clothingImage->convertFromImage(shirt.getImage());
    QLabel * myLabel = new QLabel();
    myLabel->setPixmap(*clothingImage);
    closetUi->getClothesContainer()->layout()->addWidget(myLabel);

    QImage shirtImage2 = QImage("/home/bea/Documents/dressr/shirt.png");
    ClothingItem shirt2 = ClothingItem(shirtImage2, "shirt");
    closet.addItem(shirt2);

    QPixmap* clothingImage2 = new QPixmap();
    clothingImage->convertFromImage(shirt2.getImage());
    QLabel * myLabel2 = new QLabel();
    myLabel2->setPixmap(*clothingImage2);



   closetUi->getClothesContainer()->layout()->addWidget(myLabel2);
   */

    w.show();

    return a.exec();
}
