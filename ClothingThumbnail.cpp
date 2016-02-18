#include "ClothingThumbnail.h"
#include <QPixmap>
#include <QEvent>

ClothingThumbnail::ClothingThumbnail(ClothingItem someClothing)
: itemId(someClothing.getItemID())
{
    QPixmap* clothingImage = new QPixmap();
    clothingImage->convertFromImage(someClothing.getThumbnail());
    this->setPixmap(*clothingImage);
    setAttribute(Qt::WA_AcceptTouchEvents);
    connect(&touchTimer, SIGNAL(timeout()), this, SLOT(selectionTimerTimeout()));
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
}

void ClothingThumbnail::handleTouchEnd()
{	
	touchTimer.stop();
}
