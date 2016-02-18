#include "addClothesConfirmationUi.h"
#include "ui_AddClothesConfirmationUi.h"



AddClothesConfirmationUi::AddClothesConfirmationUi()
    : ui(new Ui::AddClothesConfirmationUi)
{
    ui->setupUi(this);

    connect(ui->confirmButton, SIGNAL(clicked()),
            this, SLOT(itemConfirmed()));

    connect(ui->denyButton, SIGNAL(clicked()),
            this, SLOT(itemRejected()));
}

AddClothesConfirmationUi::~AddClothesConfirmationUi()
{
}

void AddClothesConfirmationUi::itemConfirmed()
{

    emit confirmItem();
}

void AddClothesConfirmationUi::itemRejected()
{

    emit rejectItem();
}

void AddClothesConfirmationUi::setImage(QString path)
{
//    QImage photo(path);
//    QPixmap* clothingImage = new QPixmap();
//    clothingImage->convertFromImage(photo);

//    QLabel* imageLabel = new QLabel();
//    imageLabel->setAlignment(Qt::AlignCenter);
//    imageLabel->setPixmap(*clothingImage);
//    ui->clothesItem->layout()->addWidget(imageLabel);
}
