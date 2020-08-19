#include <langslistmodel.h>

LangsListModel::LangsListModel(QObject *parent)
    :QAbstractListModel(parent)
{

}

LangsListModel::LangsListModel(const std::map<int, std::pair<std::string, std::string> > &_langsList, QObject *parent)
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
        QString langNameQStr = QString::fromStdString(langsList.at(index.row()).first);
        return QVariant(langNameQStr);
    } else {
        return QVariant();
    }
}
