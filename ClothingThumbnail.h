#ifndef CLOTHING_THUMBNAIL_H
#define CLOTHING_THUMBNAIL_H

#include <QLabel>
#include <QTimer>
#include "clothingitem.h"

class QEvent;

class ClothingThumbnail : public QLabel
{
	Q_OBJECT
public:
	ClothingThumbnail(ClothingItem someClothing);
	~ClothingThumbnail();
	bool event(QEvent* event);

public slots:
	void selectionTimerTimeout();

signals:
	void clothingSelected(int);


private:
	int itemId;
    QTimer touchTimer;

    void handleTouchBegin();
    void handleTouchEnd();
};

#endif // CLOTHING_THUMBNAIL_H
