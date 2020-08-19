#include <langslistmodel.h>

LangsListModel::LangsListModel(QObject *parent)
    :QAbstractListModel(parent)
{

}

LangsListModel::LangsListModel(const LanguagesList &_langsList, QObject *parent)
    :QAbstractListModel(parent), langsList(_langsList)
{

}

int LangsListModel::rowCount(const QModelIndex &parent) const
{
   return langsList.size();
}

QVariant LangsListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= langsList.size())
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole) {
        QString langNameQStr = QString::fromStdString(langsList.at(index.row()).name);
        return QVariant(langNameQStr);
    } else {
        return QVariant();
    }
}
