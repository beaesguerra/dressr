#include "PickUi.h"
#include "ui_PickUi.h"

#include <QEvent>
#include <QTouchEvent>
#include <QDebug>
#include <QLabel>
#include <vector>

#include "clothingitem.h"

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
			foreach(QLabel* clothingImage, currentOutfit){
				delete clothingImage;
			}
			currentOutfit.clear();
			emit outfitRejected();
		}
	}
}

void PickUi::showOutfit(Outfit anOutfit)
{
    clearView();
	foreach (ClothingItem clothing, anOutfit.getOutfit()){
        QPixmap* clothingImage = new QPixmap();
        clothingImage->convertFromImage(clothing.getThumbnail());
	
        QLabel* imageLabel = new QLabel();
        imageLabel->setAlignment(Qt::AlignCenter);
        imageLabel->setPixmap(*clothingImage);
		
        currentOutfit.append(imageLabel);
		ui->outfitContainer->layout()->addWidget(imageLabel);	
	}
}

void PickUi::clearView() {
    foreach(QLabel* clothingImage, currentOutfit){
        delete clothingImage;
    }
}
