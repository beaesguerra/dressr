#pragma once 

#include <QWidget>

namespace Ui {
    class DressrUi;
}

class DressrUi : public QWidget
{
    Q_OBJECT
public: 
    explicit DressrUi();
    ~DressrUi();

private:
    Ui::DressrUi *ui_; 
};