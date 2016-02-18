#ifndef CLOTHES_CONTAINER_H
#define CLOTHES_CONTAINER_H

#include <QWidget>

class QTouchEvent;

class ClothesContainer : public QWidget
{
	Q_OBJECT
public:
	ClothesContainer();
	~ClothesContainer();

	bool event(QEvent* event);

signals:
	void scrollUpDown(double dy);

private:
    bool touchStarted;
    QPointF touchStart;

    void handleTouchBegin(QTouchEvent* touch);
    void handleTouchEnd(QTouchEvent* touch);
    void handleTouchUpdate(QTouchEvent* touch);
};

#endif // CLOTHES_CONTAINER_H