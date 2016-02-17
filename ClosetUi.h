#ifndef CLOSET_UI_H
#define CLOSET_UI_H

#include <QWidget>
#include "clothingitem.h";
class QGridLayout;

namespace Ui 
{
	class ClosetUi;
}

class ClosetUi : public QWidget
{
    Q_OBJECT

public:
    ClosetUi();
    QWidget* getClothesContainer();
    void AddClothes(ClothingItem someClothing);
    ~ClosetUi();

private:
	QGridLayout* clothesContainerLayout;
    Ui::ClosetUi * ui;
};

#endif // CLOSET_UI_H
