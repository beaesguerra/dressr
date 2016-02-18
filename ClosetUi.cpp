#include "ClosetUi.h"
#include "ui_ClosetUi.h"
#include "QLineEdit"

#include <QGridLayout>
#include <QLabel>
#include <QTouchEvent>
#include <QScrollBar>
#include "ClothesContainer.h"

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
    this->closet = closet;
    connect(ui->filters, SIGNAL(currentIndex(QString)), this, SLOT(FilterSelected(QString)));

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
    QPixmap* clothingImage = new QPixmap();
    clothingImage->convertFromImage(someClothing.getThumbnail());
    QLabel* clothingLabel = new QLabel();
    clothingLabel->setPixmap(*clothingImage);

    clothesContainerLayout->addWidget(clothingLabel, rowCount, columnCount);
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
}

void ClosetUi::FilterSelected(QString filter)
{
    string type = filter.toStdString();
    ClearView();
    vector<ClothingItem> temp = closet->getAll(type);
    if (temp.size() == 0)
        return;
    for(unsigned int i = 0; i < temp.size(); i++)
        AddClothesToView(temp.at(i));
}

void ClosetUi::setScrollBar(double dy)
{  
    QScrollBar* scrollBar = ui->scrollArea->verticalScrollBar();
    scrollBar->setValue(scrollBar->value() + dy);
}
