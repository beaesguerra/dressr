#ifndef DRESSR_H
#define DRESSR_H

#include "closet.h"
#include "metadatawriter.h"
#include <QWidget>

namespace Ui {
class Dressr;
}

class Dressr : public QWidget
{
    Q_OBJECT

public:
    explicit Dressr(QWidget *parent = 0);
    ~Dressr();

private:
    Ui::Dressr *ui;
    MetaDataWriter mdWriter;
    Closet closet;
};

#endif // DRESSR_H
