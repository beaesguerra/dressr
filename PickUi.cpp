#include "PickUi.h"
#include "ui_PickUi.h"

#include <QEvent>
#include <QTouchEvent>
#include <QDebug>

PickUi::PickUi() 
: ui(new Ui::PickUi)
// , touchStarted(false)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_AcceptTouchEvents);
	ui->outfitContainer->setStyleSheet("background-color:grey");
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
	ui->outfitContainer->setStyleSheet("background-color:green");
    if(touch->touchPoints().isEmpty()){
		return;
	} 
	else{
//		touchStarted = true;
//		this->touchStart = touch->touchPoints().first().normalizedPos();
	}
}

void PickUi::handleTouchEnd(QTouchEvent* touch)
{
	ui->outfitContainer->setStyleSheet("background-color:blue");
	// if(!touchStarted || touch->touchPoints().isEmpty()){
	// 	return;
	// }
	// else {
	// 	touchStarted = false;
	// 	QPointF touchDelta = this->touchStart;
	// 	touchDelta -= touch->touchPoints().first().normalizedPos(); 
	// 	if(touchDelta.x() < -0.25 && (qAbs(touchDelta.y()) < qAbs(touchDelta.x()))){
	// 		emit rejected();
	// 		ui->outfitContainer->setStyleSheet("background-color:green");
	// 	} else {
	// 		ui->outfitContainer->setStyleSheet("background-color:blue");
	// 	}
	// }
}

void PickUi::handleTouchUpdate(QTouchEvent* touch)
{

}
