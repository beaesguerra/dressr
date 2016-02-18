#include "wardrobepicker.h"

WardrobePicker::WardrobePicker(Closet * closet, PickUi* pickUi, ClosetUi* closetUi)
    : m_closet(closet)
    , m_pickUi(pickUi)
    , m_closetUi(closetUi)
{
    connect(pickUi, SIGNAL(outfitRejected()), this, SLOT(randomizeOutfit()));
       connect(closetUi, SIGNAL(deleteClothing()), this, SLOT(randomizeOutfit()));
}

void WardrobePicker::randomizeOutfit()
{
    vector <string> allTypes = m_closet->getTypes();
    vector <ClothingItem> outfit;
    outfit.clear();
//    for(unsigned int i = 0; i < allTypes.size(); i++)
//    {
//        outfit.push_back(pickItem(allTypes.at(i)));
//    }
    outfit.push_back(pickItem("Top")); //currently supports only picking top and bottom
    outfit.push_back(pickItem("Bottom"));
    m_pickUi->showOutfit(outfit);
}

void WardrobePicker::checkIfNoClothesOfType(ClothingItem item)
{
    if (m_closet->getAll(item.getType()).size() == 1)
        randomizeOutfit();
}

ClothingItem WardrobePicker::pickItem(const string type)
{
    unsigned int size = m_closet->getAll().size();
    vector <ClothingItem> sameType;
    vector <ClothingItem> allItems = m_closet->getAll();
    for (unsigned int i = 0; i < size; i++)
    {
        ClothingItem temp = allItems.at(i);
        if (temp.getType().compare(type) == 0)
        {
            sameType.push_back(temp); //Get vector of all items with the same type
        }
    }
    if (sameType.size() == 0)
        return ClothingItem();
    int randomIndex = rand() % sameType.size();
    return sameType.at(randomIndex);
}

//void WardrobePicker::addRejectedItem(ClothingItem item)
//{
//    m_rejectedItems.push_back(item);
//}
