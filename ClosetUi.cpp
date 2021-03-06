#include "ClosetUi.h"
#include "ui_ClosetUi.h"
#include "QLineEdit"

#include <QGridLayout>
#include <QLabel>
#include <QTouchEvent>
#include <QScrollBar>
#include "ClothesContainer.h"
#include "ClothingThumbnail.h"
#include <QDebug>
#include <QMessageBox>
#include <QApplication>
#include <QScreen>

static int columnCount = 0;
static int rowCount = 0;

ClosetUi::ClosetUi(Closet * closet)
    : ui(new Ui::ClosetUi)
    , clothesContainerLayout(new QGridLayout())
{
    ui->setupUi(this);
    ClothesContainer* clothesContainer = new ClothesContainer();
    ui->scrollAreaWidgetContents->layout()->addWidget(clothesContainer);

    connect(clothesContainer, SIGNAL(scrollUpDown(double)),
            this, SLOT(setScrollBar(double)));

    clothesContainer->setLayout(clothesContainerLayout);
    clothesContainerLayout->setColumnStretch(0, 1);
    clothesContainerLayout->setColumnStretch(1, 1);
    clothesContainerLayout->setColumnStretch(2, 1);
    clothesContainerLayout->setAlignment(Qt::AlignTop|Qt::AlignHCenter);
    this->closet = closet;
    SetTypes(closet->getTypes());
    connect(ui->filters, SIGNAL(currentIndexChanged(QString)), this, SLOT(FilterSelected(QString)));

}

ClosetUi::~ClosetUi()
{
}


void ClosetUi::SetTypes(vector<string> types) {
    for(unsigned int i = 0; i < types.size(); i++)
        ui->filters->addItem(QString::fromStdString(types.at(i)));
}

void ClosetUi::AddType(QString type) { //TODO
    ui->filters->addItem(type);
    clothesContainerLayout->setColumnStretch(2, 1);
}


void ClosetUi::AddClothesToView(ClothingItem someClothing)
{
    ClothingThumbnail* clothingThumbnail = new ClothingThumbnail(someClothing);

    connect(clothingThumbnail, SIGNAL(clothingSelected(int)), this, SLOT(clothingSelected(int)));
    connect(clothingThumbnail, SIGNAL(clothingSelected(int)), this, SLOT(FilterSelected()));
    clothesContainerLayout->addWidget(clothingThumbnail, rowCount, columnCount);
    columnCount++;
    if (columnCount == 3)
    {
        columnCount = 0;
        rowCount++;
    }

}

void ClosetUi::ClearView() {
    while( clothesContainerLayout->count() ) {
        QWidget* widget = clothesContainerLayout->itemAt(0)->widget();
        if( widget ) {
            clothesContainerLayout->removeWidget(widget);
            delete widget;
        }
    }
    columnCount = 0;
}

void ClosetUi::AddDefaultLayout()
{
    QImage * defaultThumbnail = new QImage(":/Resources/whiteshirt.png");
    ClothingItem * defaultShirt = new ClothingItem();
    defaultShirt->setImage(*defaultThumbnail);
    ClothingThumbnail* clothingThumbnail = new ClothingThumbnail(*defaultShirt, false, false);
    clothingThumbnail->setStyleSheet("background-color: none; border: none;");
    clothesContainerLayout->addWidget(clothingThumbnail, 1, 1);

    QImage * whiteSpace = new QImage(":/Resources/whitespace.png");
    ClothingItem * defaultSpace = new ClothingItem();
    defaultSpace->setThumbnail(*whiteSpace);
    ClothingThumbnail* whiteThumbnail = new ClothingThumbnail(*defaultSpace, false);
    whiteThumbnail->setStyleSheet("background-color: none; border: none;");
    for (int i = 0; i < 3; i++){
        clothesContainerLayout->addWidget(whiteThumbnail, 0, i);
    }
}

void ClosetUi::FilterSelected(QString filter)
{
    string type = filter.toStdString();
    ClearView();
    vector<ClothingItem> temp;
    if (filter.compare("All") == 0)
    {
        temp = closet->getAll();
        if (temp.size() == 0)
            AddDefaultLayout();
        for (unsigned int i = 0; i < temp.size(); i++)
            AddClothesToView(temp.at(i));
    }
    else
    {
        temp = closet->getAll(type);
        if (temp.size() == 0)
            AddDefaultLayout();
        for(unsigned int i = 0; i < temp.size(); i++)
            AddClothesToView(temp.at(i));
    }
}

void ClosetUi::FilterSelected()
{
    QString filter = ui->filters->currentText();
    FilterSelected(filter);
}
    
void ClosetUi::setScrollBar(double dy)
{  
    QScrollBar* scrollBar = ui->scrollArea->verticalScrollBar();
    scrollBar->setValue(scrollBar->value() + dy);
}

void ClosetUi::clothingSelected(int itemId)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Item", "Are you sure?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        emit deleteClothing(itemId);
        // TODO clear screen
        emit deleteClothing();
    } 
}
