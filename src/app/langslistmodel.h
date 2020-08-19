#ifndef LANGSLISTMODEL_H
#define LANGSLISTMODEL_H
#include <QAbstractListModel>
#include <map>

class LangsListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit LangsListModel(QObject *parent = nullptr);
    LangsListModel(const std::map<int, std::pair<std::string, std::string>> &_langsList, QObject* parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const override;

private:
    std::map<int, std::pair<std::string, std::string>>langsList;
};

#endif
