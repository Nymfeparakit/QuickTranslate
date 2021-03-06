#ifndef LANGUAGESLIST_H
#define LANGUAGESLIST_H

#include <QObject>
#include <string>

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
    std::vector<LanguageItem> items() const; // get items but as vector
    void append(LanguageItem item);
    int size() const;
    LanguageItem at(const int index) const; // get item at specified index

signals:

public slots:

private:
    std::vector<LanguageItem> mItems;
};

#endif // LANGUAGESLIST_H
