#ifndef WARDROBEPICKER_H
#define WARDROBEPICKER_H

#include "outfit.h"
#include "closet.h"
#include "clothingitem.h"
#include <vector>
#include <string>
#include "PickUi.h"

using namespace std;

class WardrobePicker
{
public:
    WardrobePicker(Closet * closet);
    void randomizeOutfit();
    /**
      Returns a ClothingItem with an itemID of -1 if no items of the same type are present
     */
    ClothingItem pickItem(string type);
//    void addRejectedItem(ClothingItem item);

private:
//    vector <unsigned int> m_rejectedItems;
    Closet * m_closet;
    PickUi * m_pickUi;
};

#endif // WARDROBEPICKER_H
