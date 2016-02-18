#include "ClosetUi.h"
#include "ui_ClosetUi.h"
#include "QLineEdit"

#include <QGridLayout>
#include <QLabel>
<<<<<<< HEAD
#include <QString>
ClosetUi::ClosetUi()
: ui(new Ui::ClosetUi)
, clothesContainerLayout(new QGridLayout())
=======
#include <QTouchEvent>
#include <QScrollBar>

static int columnCount = 0;
static int rowCount = 0;

ClosetUi::ClosetUi()
    : ui(new Ui::ClosetUi)
    , clothesContainerLayout(new QGridLayout())
{
    ui->setupUi(this);
    setAttribute(Qt::WA_AcceptTouchEvents);

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
=======
    clothesContainerLayout->setColumnStretch(2, 1);
}

ClosetUi::~ClosetUi()
{
}

bool ClosetUi::event(QEvent *event)
{
    if (event->type() == QEvent::TouchBegin) {
        handleTouchBegin(static_cast<QTouchEvent*>(event));
        return true;
    }
    else if (event->type() == QEvent::TouchEnd) {
        handleTouchEnd(static_cast<QTouchEvent*>(event));
        return true;
    }
    else if (event->type() == QEvent::TouchUpdate) {
        handleTouchUpdate(static_cast<QTouchEvent*>(event));
        return true;
    }
    return QWidget::event(event);
>>>>>>> a8f8e81cb7dfe635ec370ca25ec8e9aa48db1b90
}

QWidget* ClosetUi::getClothesContainer()
{
    return  ui->clothesContainer;
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

void ClosetUi::handleTouchBegin(QTouchEvent* touch)
{
    if (touch->touchPoints().isEmpty()) {
        return;
    }
    else {
        touchStarted = true;
        this->touchStart = touch->touchPoints().first().pos();
    }
}

void ClosetUi::handleTouchEnd(QTouchEvent* touch)
{
    if (!touchStarted || touch->touchPoints().isEmpty()) {
        return;
    }
    else {
        handleTouchUpdate(touch);
        touchStarted = false;
    }
}

void ClosetUi::handleTouchUpdate(QTouchEvent* touch)
{
    if (!touchStarted || touch->touchPoints().isEmpty()) {
        return;
    }
    else {
        QPointF touchDelta = this->touchStart;
        touchDelta -= touch->touchPoints().first().pos();

        // ui->clothesContainer->setStyleSheet("background-color:red");
        QScrollBar* scrollBar = ui->scrollArea->verticalScrollBar();
        if (qAbs(touchDelta.y()) > qAbs(touchDelta.x())) {
            // ui->clothesContainer->setStyleSheet("background-color:green");
            scrollBar->setValue(scrollBar->value() + touchDelta.y());
        }
        this->touchStart = touch->touchPoints().first().pos();
    }
}
