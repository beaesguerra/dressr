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
    void AddClothesToView(ClothingItem someClothing);
    void ClearView();
    ~ClosetUi();

public slots:
	void setScrollBar(double dy);

private:
    Ui::ClosetUi * ui;
	QGridLayout* clothesContainerLayout;
};
#endif // CLOSET_UI_H
