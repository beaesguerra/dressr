#ifndef WARDROBEPICKER_H
#define WARDROBEPICKER_H

#include "outfit.h"
#include "closet.h"
#include "clothingitem.h"
#include <vector>

class WardrobePicker
{
public:
    WardrobePicker(Closet* closet);
    Outfit randomizeOutfit();
    void addRejectedItem(ClothingItem item);

private:
    vector <unsigned int> m_rejectedItems;
    Closet* m_closet;
};

#endif // WARDROBEPICKER_H
