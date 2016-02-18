#include "addClothesConfirmationUi.h"
#include "ui_AddClothesConfirmationUi.h"

#include <QDebug>
#include <QFile>
#include <QTransform>

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
    ClothingItem item(m_image, ui->comboBox->currentText().toStdString());

    emit confirmItem(item);
}

void AddClothesConfirmationUi::itemRejected()
{
    emit rejectItem();
}

// Loads an image from disk, rotates and crops it
void AddClothesConfirmationUi::getImage(QString path)
{
    QImage img = QImage(path);

    QTransform transform;
    transform.rotate(90);

    qDebug() << img.size();

    m_image = img.scaled(ui->clothesItem->size(), Qt::KeepAspectRatioByExpanding).transformed(transform).copy(0, 116.5, 700, 716.5);
    QFile::remove(path);
}

void AddClothesConfirmationUi::setImage(QString path)
{
    getImage(path);

    if (m_image.isNull())
    {
        qDebug() << "Could not load image from disk";
        qDebug() << path;
        return;
    }
    QPixmap* clothingImage = new QPixmap();
    clothingImage->convertFromImage(m_image);

    QLabel* imageLabel = new QLabel();
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setPixmap(*clothingImage);
    ui->clothesItem->layout()->setContentsMargins(0, 0, 0, 0);

    // Clear previous item
    QLayoutItem* item = ui->clothesItem->layout()->takeAt( 0 );
    if (item != NULL)
    {
        delete item->widget();
        delete item;
    }

    ui->clothesItem->layout()->addWidget(imageLabel);
}
