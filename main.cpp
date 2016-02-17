#include "dressr.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dressr w;
    w.show();

    return a.exec();
}
