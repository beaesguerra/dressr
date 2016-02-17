#include <closet.h>

Closet::Closet()
{
    m_availableTypes.push_back("Top"); //initialize default types
    m_availableTypes.push_back("Bottom");
    m_availableTypes.push_back("Overall");
}

void Closet::addType(const string type)
{
    if (type == null)
        return;
    m_availableTypes.push_back(type);
}

void Closet::removeType(const string type)
{
    if (type == null)
        return;
    m_availableTypes.erase(std::remove(m_availableTypes.begin(), m_availableTypes.end(), type), m_availableTypes.end());
//    for(int i = 0; i < m_availableTypes.size(); i++)
//    {
//        if(strcmp(m_availableTypes.at(i), type) == 0)
//        {
//            m_availableTypes.erase(m_availableType.begin() + i);
//            break;
//        }
//    }
}

ClothingItem Closet::getItem(unsigned int itemID)
{

}

vector <ClothingItem> Closet::getAll()
{
    return m_availableTypes;
}

vector <ClothingItem> Closet::getAll(const string type)
{

}
