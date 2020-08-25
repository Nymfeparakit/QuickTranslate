#include "languageslist.h"

LanguagesList::LanguagesList(QObject *parent) : QObject(parent)
{

}

LanguagesList::LanguagesList(const LanguagesList &other)
{
    int a = 0;
    mItems = other.items();
}

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
