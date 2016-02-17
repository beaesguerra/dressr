#include "DressrUi.h"
#include "ui_DressrUi.h"

#include "PickUi.h"
#include "ClosetUi.h"

DressrUi::DressrUi() 
: ui(new Ui::DressrUi)
, pickUi(new PickUi)
, closetUi(new ClosetUi)
{
    ui->setupUi(this);
    ui->stackedTabWidget->addWidget(pickUi);
    ui->stackedTabWidget->addWidget(closetUi);

    connect(ui->pickTab, SIGNAL(clicked()),
    		this, SLOT(pickTabClicked()));
    connect(ui->closetTab, SIGNAL(clicked()),
    		this, SLOT(closetTabClicked()));
}

ClosetUi * DressrUi::getClosetUi()
{
    return closetUi;
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

