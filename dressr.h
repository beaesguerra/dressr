#ifndef DRESSR_H
#define DRESSR_H

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
};

#endif // DRESSR_H
