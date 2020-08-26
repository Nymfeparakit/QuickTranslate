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
    void onTranslate(); // method is called when user demands translation
    void onOpenTranslatedTextWindow(); // method is called when window with only translated text is opened
    void onOpenMainWindow();// method is called when main window with source and translated text is opened
    LanguagesList* loadLanguagesList(); // get from current translator languages list

private:
    IMainView *mainView;
    GoogleTranslator translator;
};

#endif // MAINPRESENTER_H
