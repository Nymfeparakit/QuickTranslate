#include "languageslist.h"

LanguagesList::LanguagesList(QObject *parent) : QObject(parent)
{

}

LanguagesList::LanguagesList(const LanguagesList &l)
{
   mItems = l.items();
}

QVector<LanguageItem> LanguagesList::items() const
{
   return mItems;
}

void LanguagesList::append(LanguageItem item)
{
    mItems.append(item);
}

int LanguagesList::size() const
{
    return mItems.count();
}

LanguageItem LanguagesList::at(const int index) const
{
   return mItems.at(index);
}
