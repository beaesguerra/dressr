#include "ClosetUi.h"
#include "ui_ClosetUi.h"
#include "QLineEdit"

#include <QGridLayout>
#include <QLabel>
#include <QString>
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

void ClosetUi::SetTypes(vector<string> types) {
    for(unsigned int i = 0; i < types.size(); i++)
        ui->filters->addItem(QString::fromStdString(types.at(i)));
}

void ClosetUi::AddType(QString type) {
       ui->filters->addItem(type);
}

QWidget* ClosetUi::getClothesContainer()
{
    return  ui->clothesContainer;
}

static int columnCount = 0;
static int rowCount = 0;    // maybe 1

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

ClosetUi::~ClosetUi()
{
}
