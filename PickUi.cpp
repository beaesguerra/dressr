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
, currentMessage(0)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_AcceptTouchEvents);

    rejectionMessages.append("How about this outfit?");
    rejectionMessages.append("What about this one?");
    rejectionMessages.append("Is this one better?");
    rejectionMessages.append("Do you like this?");
    rejectionMessages.append("Is this okay?");

    connect(this, SIGNAL(outfitRejected()), this, SLOT(rejectBackground()));
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
			foreach(QLabel* clothingImage, currentOutfit){
				delete clothingImage;
			}
			currentOutfit.clear();
			emit outfitRejected();
        }
        else if(touchDelta.x() > ((this->width())/6) && (qAbs(touchDelta.y()) < qAbs(touchDelta.x()))){
            ui->label->setText("I'm glad you like it!");
        }
	}
}

void PickUi::handleTouchUpdate(QTouchEvent* touch)
{

    if(!touchStarted || touch->touchPoints().isEmpty()){
        return;
    }
    else {
        QPointF touchDelta = this->touchStart;
        touchDelta -= touch->touchPoints().first().pos();

        // Swiping right
//        if (touchDelta.x() > 0)
//            ui->outfitContainer->setStyleSheet("background-color: red");
//        else // Swiping left
//            ui->outfitContainer->setStyleSheet("background-color: green");
    }
}

void PickUi::showOutfit(Outfit anOutfit)
{
    clearView();
	foreach (ClothingItem clothing, anOutfit.getOutfit()){
        QPixmap* clothingImage = new QPixmap();
        clothingImage->convertFromImage(clothing.getImage());
	
        QLabel* imageLabel = new QLabel();
        imageLabel->setAlignment(Qt::AlignCenter);
        imageLabel->setPixmap(*clothingImage);
		
        currentOutfit.append(imageLabel);
        ui->outfitContainer->layout()->addWidget(imageLabel);
        ui->outfitContainer->setStyleSheet("background-color: white");
    }
}

void PickUi::clearView() {
    if (currentOutfit.size() == 0)
        return;
    foreach(QLabel* clothingImage, currentOutfit){
        delete clothingImage;
    }
    currentOutfit.clear();
}

void PickUi::rejectBackground()
{
    ui->label->setText(rejectionMessages.at(currentMessage));
    currentMessage++;
    if (currentMessage >= rejectionMessages.length())
        currentMessage = 0;
}
