#include <closet.h>

#include <QJsonArray>
#include <QJsonObject>


Closet::Closet()
{
    m_availableTypes.push_back("All"); //initialize default types
    m_availableTypes.push_back("Top");
    m_availableTypes.push_back("Bottom");
}

void Closet::addItem(const ClothingItem item)
{
    m_items.push_back(item);
}

void Closet::removeItem(int itemID)
{
    for (unsigned int i = 0; i < m_items.size(); i++)
    {
        if (m_items.at(i).getItemID() == itemID)
        {
            m_items.erase(m_items.begin() + i);
            break;
        }
    }
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

ClothingItem Closet::getItem(int itemID)
{
    ClothingItem temp;
    for (unsigned int i = 0; i< m_items.size(); i++)
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

vector <string> Closet::getTypes()
{
    return m_availableTypes;
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

void Closet::read(const QJsonObject &jObj)
{
    QJsonArray clothes = jObj["Clothes"].toArray();

    for (int i = 0; i < clothes.size(); i++)
    {
        QJsonObject jItem = clothes[i].toObject();
        ClothingItem item;
        item.read(jItem);
        addItem(item);
    }
}

void Closet::write(QJsonObject &jObj)
{
    QJsonArray clothes;

    for (unsigned int i = 0; i < m_items.size(); i++)
    {
        QJsonObject jItem;
        m_items[i].write(jItem);
        clothes.append(jItem);
    }
    jObj["Clothes"] = clothes;
}
