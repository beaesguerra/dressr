#ifndef CLOSET_UI_H
#define CLOSET_UI_H

#include <QWidget>
#include "clothingitem.h"
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
    void AddClothesToView(ClothingItem someClothing);
    void AddType(QString type);
    void SetTypes(vector<string> types);
    ~ClosetUi();
public slots:
    void PickFilterSelected();
    void FilterSelected();
private:
	QGridLayout* clothesContainerLayout;
    Ui::ClosetUi * ui;
};

#endif // CLOSET_UI_H
