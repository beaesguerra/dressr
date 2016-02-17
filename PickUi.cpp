#include "PickUi.h"
#include "ui_PickUi.h"

PickUi::PickUi() 
: ui(new Ui::PickUi)
{
    ui->setupUi(this);
}

PickUi::~PickUi()
{
}
