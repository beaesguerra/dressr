#include <outfit.h>

Outfit::Outfit(vector <ClothingItem> outfit)
{
    m_outfit = outfit;
}
Outfit::Outfit()
{

}
vector <ClothingItem> Outfit::getOutfit()
{
    return m_outfit;
}
