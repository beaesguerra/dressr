#include "AddUi.h"
#include "ui_AddUi.h"

#include <QObject>
#include <QQuickItem>
#include <QDebug>

#include <QDir>
#include <QStandardPaths>

AddUi::AddUi()
: ui(new Ui::AddUi)
{
    ui->setupUi(this);

    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/dressrCamera.qml")));
    QQuickItem *item = ui->quickWidget->rootObject();
    ui->quickWidget->setMinimumHeight(ui->quickWidget->width());
    qDebug() << ui->quickWidget->width();

    // Add path for camera to save files
    QString stdPath = QStandardPaths::standardLocations(QStandardPaths::HomeLocation)[0];
    QString path = QDir(stdPath).absoluteFilePath("Dressr");

    if (!QDir(path).exists())
        QDir(path).mkpath(".");

    item->setProperty("imgPath", path);

    connect(ui->capture, SIGNAL(clicked()),
            this, SLOT(captureImage()));

    connect(item, SIGNAL(captured(QString)),
            this, SLOT(imageSaved(QString)));
}

AddUi::~AddUi()
{
}

void AddUi::captureImage() {
    ui->quickWidget->rootObject()->setProperty("readyToCapture", 1);
}

void AddUi::imageSaved(QString url)
{
//    qDebug() << url;
    emit imageTaken(url);
}
