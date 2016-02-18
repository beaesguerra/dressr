#ifndef CLOSET_UI_H
#define CLOSET_UI_H

#include <QWidget>
#include "clothingitem.h"
class QGridLayout;

namespace Ui 
{
	class ClosetUi;
}

class QTouchEvent; 

class ClosetUi : public QWidget
{
    Q_OBJECT

public:
    ClosetUi();
    QWidget* getClothesContainer();
    void AddClothesToView(ClothingItem someClothing);
    void ClearView();
    bool event(QEvent* event);
    ~ClosetUi();

private:
    Ui::ClosetUi * ui;
	QGridLayout* clothesContainerLayout;
    bool touchStarted;
    QPointF touchStart;

    void handleTouchBegin(QTouchEvent* touch);
    void handleTouchEnd(QTouchEvent* touch);
    void handleTouchUpdate(QTouchEvent* touch);
};

#endif // CLOSET_UI_H
