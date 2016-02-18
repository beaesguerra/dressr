#include "wardrobepicker.h"

WardrobePicker::WardrobePicker(Closet * closet, PickUi* pickUi, ClosetUi* closetUi)
    : m_closet(closet)
    , m_pickUi(pickUi)
    , m_closetUi(closetUi)
    , m_lastOutfit(NULL)
{
    connect(pickUi, SIGNAL(outfitRejected()), this, SLOT(randomizeOutfit()));
    connect(closetUi, SIGNAL(deleteClothing()), this, SLOT(randomizeOutfit()));
}

void WardrobePicker::randomizeOutfit()
{
    vector <string> allTypes = m_closet->getTypes();
    vector <ClothingItem> outfit;
    ClothingItem top = pickItem("Top");
    ClothingItem bottom = pickItem("Bottom");
    if (m_lastOutfit != NULL){
           while ( m_lastOutfit->getOutfit().at(0).getItemID() == bottom.getItemID() &&
            m_lastOutfit->getOutfit().at(1).getItemID() == top.getItemID() &&
               m_closet->getAll().size() > 2)
        {
            top = pickItem("Top");
            bottom = pickItem("Bottom");
        }
    }
    outfit.push_back(top); //currently supports only picking top and bottom
    outfit.push_back(bottom);
    m_pickUi->showOutfit(outfit);
    m_lastOutfit = new Outfit(outfit);
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
