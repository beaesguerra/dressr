#ifndef WARDROBEPICKER_H
#define WARDROBEPICKER_H

#include <QWidget>
#include "outfit.h"
#include "closet.h"
#include "clothingitem.h"
#include <vector>
#include "PickUi.h"

using namespace std;

class WardrobePicker : public QWidget
{
	Q_OBJECT
public:
    WardrobePicker(Closet * closet, PickUi * pickUi);

public slots:
    void randomizeOutfit();
    void checkIfNoClothesOfType(ClothingItem item);

private:
    ClothingItem pickItem(string type);
//    vector <unsigned int> m_rejectedItems;
    Closet * m_closet;
    PickUi * m_pickUi;
};

#endif // WARDROBEPICKER_H
