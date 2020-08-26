#ifndef LANGSLISTMODEL_H
#define LANGSLISTMODEL_H
#include <QAbstractListModel>
#include <map>
#include "languageslist.h"
#include "mainpresenter.h"

// model for list of languages
class LangsListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit LangsListModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const override;

    LanguagesList* langsList() const;
    void setLangsList(LanguagesList* langsList);
    ~LangsListModel();
    QHash<int, QByteArray> roleNames() const override;

private:
    LanguagesList* mLangsList; // this list contains data for model
    MainPresenter mainPresenter;

    enum {
        NameRole = Qt::UserRole //single role for language name
    };
};

#endif
