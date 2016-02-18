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
    QApplication a (argc, argv);
    MetaDataWriter * mdWriter = new MetaDataWriter();
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

    QWidget::connect(&a, SIGNAL(aboutToQuit()), mdWriter, SLOT(save()));
    QWidget::connect(&a, SIGNAL(applicationStateChanged(Qt::ApplicationState)), mdWriter, SLOT(save()));

    mdWriter->load(*closet);


        closetUi->FilterSelected("All");
    picker->randomizeOutfit(); //testing wardrobe picker


    w->show();
    return a.exec();
}
