#ifndef ADDCLOTHESCONFIRMATIONUI_H
#define ADDCLOTHESCONFIRMATIONUI_H

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
    void confirmItem();

public slots:
    void setImage(QString path);
    void itemConfirmed();
    void itemRejected();

private:
    Ui::AddClothesConfirmationUi* ui;
};

#endif // ADDCLOTHESCONFIRMATIONUI_H
