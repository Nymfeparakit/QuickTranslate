#ifndef LANGSLISTMODEL_H
#define LANGSLISTMODEL_H
#include <QAbstractListModel>
#include <map>
#include "languageslist.h"
#include "mainpresenter.h"

class LangsListModel : public QAbstractListModel
{
    Q_OBJECT
    //Q_PROPERTY(LanguagesList *langsList READ langsList WRITE setLangsList)

public:
    explicit LangsListModel(QObject *parent = nullptr);
    //LangsListModel(const LanguagesList& _langsList, QObject* parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const override;

    LanguagesList* langsList() const;
    void setLangsList(LanguagesList* langsList);
    ~LangsListModel();
    QHash<int, QByteArray> roleNames() const override;

private:
    //std::map<int, std::pair<std::string, std::string>>langsList;
    LanguagesList* mLangsList;
    MainPresenter mainPresenter;

    enum {
        NameRole = Qt::UserRole
    };
};

#endif
