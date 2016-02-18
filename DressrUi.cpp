#include "DressrUi.h"
#include "ui_DressrUi.h"

#include "PickUi.h"
#include "ClosetUi.h"
#include "AddUi.h"
#include "addClothesConfirmationUi.h"

#include <QDebug>

DressrUi::DressrUi()
{

}

DressrUi::DressrUi(PickUi * pickUi, ClosetUi * closetUi, AddUi *addUi, AddClothesConfirmationUi *addClothesConfirmation)
: ui(new Ui::DressrUi)
{
    this->pickUi = pickUi;
    this->closetUi = closetUi;
    this->addUi = addUi;
    this->addClothesConfirmation = addClothesConfirmation;
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

    connect(addClothesConfirmation, SIGNAL(confirmItem(ClothingItem)),
            this, SLOT(addTabClicked()));


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
}

