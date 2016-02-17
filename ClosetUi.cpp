#include "ClosetUi.h"
#include "ui_ClosetUi.h"
#include "QLineEdit"
ClosetUi::ClosetUi() 
: ui(new Ui::ClosetUi)
{
    ui->setupUi(this);
    //ui->filters->lineEdit()->setPlaceholderText("Filter by:");
}

ClosetUi::~ClosetUi()
{
}
