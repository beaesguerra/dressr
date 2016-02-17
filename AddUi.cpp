#include "AddUi.h"
#include "ui_AddUi.h"

AddUi::AddUi()
: ui(new Ui::AddUi)
{
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/dressrCamera.qml")));
    ui->quickWidget->show();
}

AddUi::~AddUi()
{
}
