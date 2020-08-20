#ifndef LANGUAGESLIST_H
#define LANGUAGESLIST_H

#include <QObject>
#include <string>
//#include <QVector>

struct LanguageItem {
    std::string code;
    std::string name;

    LanguageItem(std::string _code, std::string _name)
        :code(_code), name(_name) {}

    LanguageItem() = default;
    ~LanguageItem() = default;
};

class LanguagesList : public QObject
{
    Q_OBJECT
public:
    LanguagesList(QObject *parent = nullptr);
    LanguagesList(const LanguagesList& l);
    //LanguagesList& operator=(const LanguagesList&);
    //LanguagesList& operator=(LanguagesList&);
    std::vector<LanguageItem> items() const;
    void append(LanguageItem item);
    int size() const;
    LanguageItem at(const int index) const;

signals:

public slots:

private:
    //QVector<LanguageItem> mItems;
    std::vector<LanguageItem> mItems;
};

#endif // LANGUAGESLIST_H
