#include "DressrUi.h"
#include "ui_DressrUi.h"

#include "PickUi.h"

DressrUi::DressrUi() 
: ui(new Ui::DressrUi)
, pickUi(new PickUi)
{
    ui->setupUi(this);
    ui->stackedTabWidget->addWidget(pickUi);
}

DressrUi::~DressrUi()
{
}
