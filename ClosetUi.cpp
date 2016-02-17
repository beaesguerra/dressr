#include "ClosetUi.h"
#include "ui_ClosetUi.h"
#include "QLineEdit"
ClosetUi::ClosetUi() 
: ui(new Ui::ClosetUi)
{
    ui->setupUi(this);
    //ui->filters->lineEdit()->setPlaceholderText("Filter by:");
}

QWidget* ClosetUi::getClothesContainer()
{
    return  ui->clothesContainer;
}

ClosetUi::~ClosetUi()
{
}
