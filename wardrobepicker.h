#ifndef WARDROBEPICKER_H
#define WARDROBEPICKER_H

#include "outfit.h"
#include "closet.h"

class WardrobePicker
{
public:
    WardrobePicker(Closet closet);
    Outfit randomizeOutfit();

private:
    Closet m_closet;
};

#endif // WARDROBEPICKER_H
