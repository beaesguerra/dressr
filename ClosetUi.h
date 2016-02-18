#ifndef CLOSET_UI_H
#define CLOSET_UI_H

#include <QWidget>
#include "clothingitem.h"
#include "closet.h"
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
    ClosetUi(Closet * closet);
    ~ClosetUi();

    void AddClothesToView(ClothingItem someClothing);
    void SetTypes(vector<string> types);
    void AddType(QString type);
    void ClearView();

public slots:
    void FilterSelected(QString filter);
    void FilterSelected();
    void setScrollBar(double dy);

signals:
	void clothingSelected(int itemId);

private:
    Ui::ClosetUi * ui;
    QGridLayout* clothesContainerLayout;
    bool touchStarted;
    QPointF touchStart;
    Closet * closet;
};
#endif // CLOSET_UI_H
