#ifndef IMAINVIEW_H
#define IMAINVIEW_H
#include <QObject>

class IMainView : public QObject
{
    Q_OBJECT

public:
    virtual QString getSourceText() = 0;
    virtual QString getSourceLanguage() = 0;
    virtual QString getDestLanguage() = 0;

};

#endif // IMAINVIEW_H
