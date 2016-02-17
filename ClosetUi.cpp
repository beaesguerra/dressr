#include "ClosetUi.h"
#include "ui_ClosetUi.h"
#include "QLineEdit"

#include <QGridLayout>
#include <QLabel>
ClosetUi::ClosetUi() 
: ui(new Ui::ClosetUi)
, clothesContainerLayout(new QGridLayout())
{
    ui->setupUi(this);
    //ui->filters->lineEdit()->setPlaceholderText("Filter by:");
    ui->clothesContainer->setLayout(clothesContainerLayout);
    clothesContainerLayout->setColumnStretch(0, 1);
    clothesContainerLayout->setColumnStretch(1, 1);
    clothesContainerLayout->setColumnStretch(2, 1);  
}

QWidget* ClosetUi::getClothesContainer()
{
    return  ui->clothesContainer;
}

static int columnCount = 0;
static int rowCount = 0;    // maybe 1

void ClosetUi::AddClothes(ClothingItem someClothing)
{
    QPixmap* clothingImage = new QPixmap();
    clothingImage->convertFromImage(someClothing.getThumbnail());
    QLabel* clothingLabel = new QLabel();
    clothingLabel->setPixmap(*clothingImage);

    clothesContainerLayout->addWidget(clothingLabel, rowCount, columnCount);
    //if (rowCount )
}

ClosetUi::~ClosetUi()
{
}
