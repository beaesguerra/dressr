#include "ClosetUi.h"
#include "ui_ClosetUi.h"

ClosetUi::ClosetUi() 
: ui(new Ui::ClosetUi)
{
    ui->setupUi(this);
}

QWidget* ClosetUi::getClothesContainer()
{
    return  ui->clothesContainer;
}

ClosetUi::~ClosetUi()
{
}
