#ifndef OUTFIT_H
#define OUTFIT_H

#include <clothingitem.h>
#include <vector>

class Outfit
{
public:
   Outfit(vector <ClothingItem> outfit);
   vector <ClothingItem> getOutfit();
   Outfit();

private:
   vector <ClothingItem> m_outfit;
};
#endif // OUTFIT_H
