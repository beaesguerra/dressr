#include "PickUi.h"
#include "ui_PickUi.h"

#include <QEvent>
#include <QTouchEvent>
#include <QDebug>

PickUi::PickUi() 
: ui(new Ui::PickUi)
, touchStarted(false)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_AcceptTouchEvents);
}

PickUi::~PickUi()
{
}

bool PickUi::event(QEvent *event)
{
    if (event->type() == QEvent::TouchBegin){
        handleTouchBegin(static_cast<QTouchEvent*>(event));
    	return true;
    }
    else if (event->type() == QEvent::TouchEnd){
        handleTouchEnd(static_cast<QTouchEvent*>(event));
    	return true;
    }
    else if (event->type() == QEvent::TouchUpdate){
        handleTouchUpdate(static_cast<QTouchEvent*>(event));
    	return true;
    }
    return QWidget::event(event);
}

void PickUi::handleTouchBegin(QTouchEvent* touch)
{
    if(touch->touchPoints().isEmpty()){
		return;
	} 
	else{
		touchStarted = true;
		this->touchStart = touch->touchPoints().first().pos();
	}
}

void PickUi::handleTouchEnd(QTouchEvent* touch)
{
	if(!touchStarted || touch->touchPoints().isEmpty()){
		return;
	}
	else {
		touchStarted = false;
		QPointF touchDelta = this->touchStart;
		touchDelta -= touch->touchPoints().first().pos();
		if(touchDelta.x() < -((this->width())/6) && (qAbs(touchDelta.y()) < qAbs(touchDelta.x()))){
			emit rejected();
			ui->outfitContainer->setStyleSheet("background-color:green");
		} else {
			ui->outfitContainer->setStyleSheet("background-color:red");
		}
	}
}

void PickUi::handleTouchUpdate(QTouchEvent* touch)
{

}
