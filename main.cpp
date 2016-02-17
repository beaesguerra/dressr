#include "DressrUi.h"
#include <QApplication>

#include "closet.h"
#include "clothingitem.h"
#include "metadatawriter.h"
#include "QImage"
#include "QLabel"
#include <QPixmap>
#include "ClosetUi.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DressrUi w;

    ClosetUi * closetUi= w.getClosetUi();
    QImage shirtImage = QImage("shirt.png");
    ClothingItem shirt = ClothingItem(shirtImage, "shirt");
    Closet closet;
    closet.addItem(shirt);
    QLabel * myLabel = new QLabel(closetUi->getClothesContainer());
    myLabel->setPixmap(QPixmap::fromImage(closet.getAll().at(0).getImage()));
    myLabel->show();

    w.show();

    return a.exec();
}
