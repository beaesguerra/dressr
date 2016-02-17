#include "DressrUi.h"
#include <QApplication>

#include "closet.h"
#include "clothingitem.h"
#include "metadatawriter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DressrUi w;
    w.show();

    return a.exec();
}
