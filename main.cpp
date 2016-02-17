#include "DressrUi.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DressrUi w;
    w.show();

    return a.exec();
}
