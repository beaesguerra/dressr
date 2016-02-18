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

ClosetUi::ClosetUi()
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
}

ClosetUi::~ClosetUi()
{
}

void ClosetUi::setScrollBar(double dy)
{  
    QScrollBar* scrollBar = ui->scrollArea->verticalScrollBar();
    scrollBar->setValue(scrollBar->value() + dy);
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
