#include "DressrUi.h"
#include "ui_DressrUi.h"

#include "PickUi.h"
#include "ClosetUi.h"

DressrUi::DressrUi()
{

}

DressrUi::DressrUi(PickUi * pickUi, ClosetUi * closetUi)
: ui(new Ui::DressrUi)
{
    this->pickUi = pickUi;
    this->closetUi = closetUi;
    ui->setupUi(this);
    ui->stackedTabWidget->addWidget(pickUi);
    ui->stackedTabWidget->addWidget(closetUi);

    connect(ui->pickTab, SIGNAL(clicked()),
    		this, SLOT(pickTabClicked()));
    connect(ui->closetTab, SIGNAL(clicked()),
    		this, SLOT(closetTabClicked()));

}

DressrUi::~DressrUi()
{
}

void DressrUi::pickTabClicked()
{
	ui->stackedTabWidget->setCurrentWidget(pickUi);
}

void DressrUi::closetTabClicked()
{
	ui->stackedTabWidget->setCurrentWidget(closetUi);
}

