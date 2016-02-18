#include "ClothingThumbnail.h"
#include <QPixmap>
#include <QEvent>

ClothingThumbnail::ClothingThumbnail(ClothingItem someClothing, bool acceptTouchEvents)
: itemId(someClothing.getItemID())
{
    QPixmap* clothingImage = new QPixmap();
    clothingImage->convertFromImage(someClothing.getThumbnail());
    this->setPixmap(*clothingImage);
    if(acceptTouchEvents){
        setAttribute(Qt::WA_AcceptTouchEvents);
    }
    connect(&touchTimer, SIGNAL(timeout()), this, SLOT(selectionTimerTimeout()));
    setStyleSheet("border: 4px solid orange; border-radius: 8px; background-color: orange;");
}

ClothingThumbnail::~ClothingThumbnail()
{
}

bool ClothingThumbnail::event(QEvent *event)
{
    if (event->type() == QEvent::TouchEnd) {
        handleTouchEnd();
        return true;
    }
    else if (event->type() == QEvent::TouchBegin) {
        handleTouchBegin();
        return true;
    }
    return QWidget::event(event);
}

void ClothingThumbnail::selectionTimerTimeout()
{
	emit clothingSelected(itemId);
}

void ClothingThumbnail::handleTouchBegin()
{	
	touchTimer.start(1000);	
    setStyleSheet("border: 4px solid #35B5D8; border-radius: 8px; background-color: #35B5D8;");
}

void ClothingThumbnail::handleTouchEnd()
{	
	touchTimer.stop();
    setStyleSheet("border: 4px solid orange; border-radius: 8px; background-color: orange;");
}
