#ifndef PICK_UI_H
#define PICK_UI_H

#include <QWidget>
#include <QPointF>
#include "outfit.h"

namespace Ui 
{
	class PickUi;
}

class QEvent;
class QTouchEvent;
class QLabel;

class PickUi : public QWidget
{
    Q_OBJECT

public:
    PickUi();
    ~PickUi();
    bool event(QEvent* event);
    void showOutfit(Outfit anOutfit);

private:
    Ui::PickUi* ui;
    bool touchStarted;
    QPointF touchStart;
    QList<QLabel*> currentOutfit;

    void handleTouchBegin(QTouchEvent* touch);
    void handleTouchEnd(QTouchEvent* touch);
    void handleTouchUpdate(QTouchEvent* touch);

signals:
	void rejected();

};

#endif // PICK_UI_H
