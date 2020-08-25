#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H
#include "imainview.h"
#include <languageslist.h>
#include "googletranslator.h"
#include "translatorworker.h"
#include <QThread>

class MainPresenter
{
public:
    MainPresenter(IMainView *_mainView);
    MainPresenter() = default;
    void setView(IMainView* _mainView);
    void onTranslate();
    void onClipboardDataChanged();
    void onOpenTranslatedTextWindow();
    void onOpenMainWindow();
    LanguagesList* loadLanguagesList();

private:
    IMainView *mainView;
    GoogleTranslator translator;
};

#endif // MAINPRESENTER_H
