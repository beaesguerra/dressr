#include <closet.h>


Closet::Closet()
{
    m_availableTypes.push_back("Top"); //initialize default types
    m_availableTypes.push_back("Bottom");
    m_availableTypes.push_back("Overall");
}

void Closet::addType(const string type)
{
    if (type.empty())
        return;
    m_availableTypes.push_back(type);
}

void Closet::removeType(const string type)
{
    if (type.empty())
        return;
    m_availableTypes.erase(remove(m_availableTypes.begin(), m_availableTypes.end(), type), m_availableTypes.end());
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
    ClothingItem temp;
    for (int i = 0; i< m_items.size(); i++)
    {
        temp = m_items.at(i);
        if(temp.getItemID() == itemID)
        {
            return temp;
        }
    }
    return temp;
}

vector <ClothingItem> Closet::getAll()
{
    return m_items;
}

vector <ClothingItem> Closet::getAll(const string type)
{
    vector<ClothingItem> sameTypes;
    if (type.empty())
        return sameTypes;
    for (int i = m_items.size() - 1; i >= 0; i--)
    {
        if(type.compare(m_items.at(i).getType())== 0)
        {
            sameTypes.push_back(m_items.at(i));
        }
    }
    return sameTypes;
}

void Closet::read(QJsonObject jObj)
{

}

void Closet::write(QJsonObject &jObj)
{

}
