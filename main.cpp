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
#include "wardrobepicker.h"
#include "AddUi.h"
#include "addClothesConfirmationUi.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MetaDataWriter mdWriter;
    PickUi * pickUi = new PickUi();
    Closet * closet = new Closet();
    AddUi * addUi = new AddUi();
    AddClothesConfirmationUi * addClothesConfirmationUi = new AddClothesConfirmationUi();
    ClosetUi * closetUi = new ClosetUi(closet);
    QWidget::connect(closetUi, SIGNAL(deleteClothing(int)), closet, SLOT(removeItem(int)));
    DressrUi * w = new DressrUi(pickUi, closetUi, addUi, addClothesConfirmationUi);
    WardrobePicker * picker = new WardrobePicker(closet, pickUi, closetUi);

    QWidget::connect(addClothesConfirmationUi, SIGNAL(confirmItem(ClothingItem)),
                     closet, SLOT(addItem(ClothingItem)));
    QWidget::connect(addClothesConfirmationUi, SIGNAL(confirmItem(ClothingItem)),
                     closetUi, SLOT(FilterSelected()));
    QWidget::connect(closet, SIGNAL(itemAdded(ClothingItem)),
                     picker, SLOT(checkIfNoClothesOfType(ClothingItem)));

    mdWriter.load(*closet);

//    QString stdPath = QStandardPaths::standardLocations(QStandardPaths::HomeLocation)[0];
//    QString filename = QDir::currentPath().append("/shirt.jpg");

//    for (int i = 0; i < 10; i++)
//    {
//        QImage shirtImage1 = QImage("/storage/emulated/0/data/testshirt.jpg");
//        ClothingItem shirt1 = ClothingItem(shirtImage1, "Top");

//        QImage shirtImage2 = QImage("/storage/emulated/0/data/testpants.jpg");
//        ClothingItem pants1 = ClothingItem(shirtImage2, "Bottom");

//        QImage shirtImage3 = QImage("/storage/emulated/0/data/shirt.png");
//        ClothingItem shirt3 = ClothingItem(shirtImage3, "Top");

//        closet->addItem(shirt1);
//        closet->addItem(pants1);
//        closet->addItem(shirt3);
        closetUi->FilterSelected("All");
//    }
    picker->randomizeOutfit(); //testing wardrobe picker


    w->show();
    int flag = a.exec();
    mdWriter.save(*closet);
    return flag;
}
