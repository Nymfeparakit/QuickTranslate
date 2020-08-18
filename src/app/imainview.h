#ifndef IMAINVIEW_H
#define IMAINVIEW_H
#include <QObject>
#include <string>

class IMainView : public QObject
{
    Q_OBJECT

public:
    virtual std::string getSourceText() = 0;
    virtual std::string getSourceLanguage() = 0;
    virtual std::string getDestLanguage() = 0;

};

#endif // IMAINVIEW_H
