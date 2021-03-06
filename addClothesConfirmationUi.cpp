#include "addClothesConfirmationUi.h"
#include "ui_AddClothesConfirmationUi.h"

#include <QCameraInfo>
#include <QDebug>
#include <QFile>
#include <QImageReader>
#include <QImageIOHandler>
#include <QTransform>
#include <QApplication>
#include <QScreen>

AddClothesConfirmationUi::AddClothesConfirmationUi()
    : ui(new Ui::AddClothesConfirmationUi)
{
    ui->setupUi(this);
    double screenWidth = QApplication::screens().at(0)->size().width();

    ui->confirmButton->setIconSize(QSize(screenWidth/4.2, screenWidth/4));
    ui->denyButton->setIconSize(QSize(screenWidth/4.2, screenWidth/4));

    connect(ui->confirmButton, SIGNAL(clicked()),
            this, SLOT(itemConfirmed()));
    connect(ui->confirmButton, SIGNAL(pressed()),
            this, SLOT(acceptPressed()));
    connect(ui->confirmButton, SIGNAL(released()),
            this, SLOT(acceptReleased()));

    connect(ui->denyButton, SIGNAL(clicked()),
            this, SLOT(itemRejected()));
    connect(ui->denyButton, SIGNAL(pressed()),
            this, SLOT(rejectPressed()));
    connect(ui->denyButton, SIGNAL(released()),
            this, SLOT(rejectReleased()));


    ui->categoryComboBox->addItem(QString::fromStdString("Top"));
    ui->categoryComboBox->addItem(QString::fromStdString("Bottom"));

}

AddClothesConfirmationUi::~AddClothesConfirmationUi()
{
}

void AddClothesConfirmationUi::itemConfirmed()
{
    ClothingItem item(m_image, ui->categoryComboBox->currentText().toStdString());

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
    QImageReader rdr(path);

    int rotation = 0;

    switch (rdr.transformation()) {
        case QImageIOHandler::TransformationNone:
            rotation = 0;
            break;
        case QImageIOHandler::TransformationRotate90:
            rotation = 90;
            break;
        case QImageIOHandler::TransformationRotate180:
            rotation = 180;
            break;
        case QImageIOHandler::TransformationRotate270:
            rotation = 270;
            break;
    }

    QTransform transform;
    transform.rotate(rotation);
    QImage rotImage = img.transformed(transform);

    QSize finalSize = ui->clothesItem->size();
    double fw = (double) finalSize.width();
    QSize expandedSize = QSize(fw, (fw / rotImage.width()) * rotImage.height());
    int x = (expandedSize.height() - fw) / 2;

    m_image = rotImage.scaled(expandedSize, Qt::KeepAspectRatioByExpanding).copy(0, x, fw, fw);
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


void AddClothesConfirmationUi::acceptPressed()
{
    QPixmap pixmap = QPixmap(":/Resources/accept-selected.png");
    QIcon icon = QIcon(pixmap);
    ui->confirmButton->setIcon(icon);
}

void AddClothesConfirmationUi::acceptReleased()
{
    QPixmap pixmap = QPixmap(":/Resources/accept.png");
    QIcon icon = QIcon(pixmap);
    ui->confirmButton->setIcon(icon);
}

void AddClothesConfirmationUi::rejectPressed()
{
    QPixmap pixmap = QPixmap(":/Resources/reject-selected.png");
    QIcon icon = QIcon(pixmap);
    ui->denyButton->setIcon(icon);
}

void AddClothesConfirmationUi::rejectReleased()
{
    QPixmap pixmap = QPixmap(":/Resources/reject.png");
    QIcon icon = QIcon(pixmap);
    ui->denyButton->setIcon(icon);
}
