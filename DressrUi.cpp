#include "DressrUi.h"
#include "ui_DressrUi.h"

#include "PickUi.h"
#include "ClosetUi.h"
#include "AddUi.h"
#include "addClothesConfirmationUi.h"

#include <QDebug>

DressrUi::DressrUi() 
: ui(new Ui::DressrUi)
, pickUi(new PickUi)
, closetUi(new ClosetUi)
, addUi(new AddUi)
, addClothesConfirmation(new AddClothesConfirmationUi)
{
    ui->setupUi(this);
    ui->stackedTabWidget->addWidget(pickUi);
    ui->stackedTabWidget->addWidget(closetUi);
    ui->stackedTabWidget->addWidget(addUi);
    ui->stackedTabWidget->addWidget(addClothesConfirmation);

    connect(ui->pickTab, SIGNAL(clicked()),
    		this, SLOT(pickTabClicked()));
    connect(ui->closetTab, SIGNAL(clicked()),
    		this, SLOT(closetTabClicked()));
    connect(ui->addTab, SIGNAL(clicked()),
            this, SLOT(addTabClicked()));

    connect(addUi, SIGNAL(imageTaken(QString)),
           this, SLOT(confirmClothes(QString)));

    connect(addUi, SIGNAL(imageTaken(QString)),
           addClothesConfirmation, SLOT(setImage(QString)));

    connect(addClothesConfirmation, SIGNAL(rejectItem()),
            this, SLOT(addTabClicked()));
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

void DressrUi::addTabClicked()
{
    ui->stackedTabWidget->setCurrentWidget(addUi);
}

void DressrUi::confirmClothes(QString path)
{
    qDebug() << path;
    ui->stackedTabWidget->setCurrentWidget(addClothesConfirmation);
//    addClothesConfirmation->setImage(path);
}

