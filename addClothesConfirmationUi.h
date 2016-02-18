#ifndef ADDCLOTHESCONFIRMATIONUI_H
#define ADDCLOTHESCONFIRMATIONUI_H

#include "clothingitem.h"

#include <QImage>
#include <QString>
#include <QWidget>

namespace Ui
{
    class AddClothesConfirmationUi;
}

class AddClothesConfirmationUi : public QWidget
{
    Q_OBJECT
public:
    AddClothesConfirmationUi();
    ~AddClothesConfirmationUi();

signals:
    void rejectItem();
    void confirmItem(ClothingItem);

public slots:
    void setImage(QString path);
    void itemConfirmed();
    void itemRejected();

private:
    void getImage(QString path);

    Ui::AddClothesConfirmationUi* ui;
    QImage m_image;
};

#endif // ADDCLOTHESCONFIRMATIONUI_H
