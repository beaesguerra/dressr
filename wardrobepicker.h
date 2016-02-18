#ifndef WARDROBEPICKER_H
#define WARDROBEPICKER_H

#include <QWidget>
#include "outfit.h"
#include "closet.h"
#include "clothingitem.h"
#include <vector>
#include "PickUi.h"
#include "ClosetUi.h"

using namespace std;

class WardrobePicker : public QWidget
{
	Q_OBJECT
public:
    WardrobePicker(Closet * closet, PickUi * pickUi, ClosetUi * closetUi);

public slots:
    void randomizeOutfit();

private:
    ClothingItem pickItem(string type);
//    vector <unsigned int> m_rejectedItems;
    Closet * m_closet;
    PickUi * m_pickUi;
    ClosetUi * m_closetUi;
};

#endif // WARDROBEPICKER_H
