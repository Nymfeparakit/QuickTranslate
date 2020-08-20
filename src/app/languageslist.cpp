#include "languageslist.h"

LanguagesList::LanguagesList(QObject *parent) : QObject(parent)
{

}

LanguagesList::LanguagesList(const LanguagesList &other)
{
    int a = 0;
    mItems = other.items();
}

/*
LanguagesList &LanguagesList::operator=(const LanguagesList &other)
{
    mItems = other.items();
    return *this;
}

LanguagesList &LanguagesList::operator=(LanguagesList &other)
{
    mItems = other.items();
    return *this;
}
*/

std::vector<LanguageItem> LanguagesList::items() const
{
   return mItems;
}

void LanguagesList::append(LanguageItem item)
{
    mItems.push_back(item);
}

int LanguagesList::size() const
{
    return mItems.size();
}

LanguageItem LanguagesList::at(const int index) const
{
   return mItems.at(index);
}
