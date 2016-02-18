#include "ClothesContainer.h"

#include <QTouchEvent>
#include <QScrollBar>

ClothesContainer::ClothesContainer()
: touchStarted(false)
{
	setAttribute(Qt::WA_AcceptTouchEvents);
	setStyleSheet("background-color: white");
}

ClothesContainer::~ClothesContainer()
{

}

bool ClothesContainer::event(QEvent *event)
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

}


void ClothesContainer::handleTouchBegin(QTouchEvent* touch)
{
    if (touch->touchPoints().isEmpty()) {
        return;
    }
    else {
        touchStarted = true;
        this->touchStart = touch->touchPoints().first().pos();
    }
}

void ClothesContainer::handleTouchEnd(QTouchEvent* touch)
{
    if (!touchStarted || touch->touchPoints().isEmpty()) {
        return;
    }
    else {
        handleTouchUpdate(touch);
        touchStarted = false;
    }
}

void ClothesContainer::handleTouchUpdate(QTouchEvent* touch)
{
    if (!touchStarted || touch->touchPoints().isEmpty()) {
        return;
    }
    else {
        QPointF touchDelta = this->touchStart;
        touchDelta -= touch->touchPoints().first().pos();

        if (qAbs(touchDelta.y()) > qAbs(touchDelta.x())) {
            emit scrollUpDown(touchDelta.y());
        }
        this->touchStart = touch->touchPoints().first().pos();
    }
}
