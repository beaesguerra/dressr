#include <outfit.h>

Outfit::Outfit(vector <ClothingItem> outfit)
{
    m_outfit = outfit;
}

vector <ClothingItem> Outfit::getOutfit()
{
    return m_outfit;
}
