#include <langslistmodel.h>

LangsListModel::LangsListModel(QObject *parent)
    :QAbstractListModel(parent)
{
    mLangsList = mainPresenter.loadLanguagesList();
    //mLangsList = new LanguagesList();
    //LanguageItem temp("code1", "name1");
    //LanguageItem temp2("code2", "name2");
    //mLangsList->append(temp);
    //mLangsList->append(temp2);
}

/*
LangsListModel::LangsListModel(const LanguagesList &_langsList, QObject *parent)
    :QAbstractListModel(parent), mLangsList(_langsList)
{

}
*/

int LangsListModel::rowCount(const QModelIndex &parent) const
{
   int a = mLangsList->size();
   return a;
   //return mLangsList->size();
}

QVariant LangsListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= mLangsList->size())
    {
        return QVariant();
    }

    if (role == NameRole) {
        QString langNameQStr = QString::fromStdString(mLangsList->at(index.row()).name);
        return QVariant(langNameQStr);
    }

    return QVariant();
}

LanguagesList* LangsListModel::langsList() const
{
    return mLangsList;
}

void LangsListModel::setLangsList(LanguagesList* langsList)
{
    mLangsList = langsList;
}

LangsListModel::~LangsListModel()
{
    delete mLangsList;
}

QHash<int, QByteArray> LangsListModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[NameRole] = "name";
    return names;
}
