#include "DressrUi.h"
#include "ui_DressrUi.h"

#include "PickUi.h"
#include "ClosetUi.h"
#include "AddUi.h"

DressrUi::DressrUi() 
: ui(new Ui::DressrUi)
, pickUi(new PickUi)
, closetUi(new ClosetUi)
, addUi(new AddUi)
{
    ui->setupUi(this);
    ui->stackedTabWidget->addWidget(pickUi);
    ui->stackedTabWidget->addWidget(closetUi);
    ui->stackedTabWidget->addWidget(addUi);

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

