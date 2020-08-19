#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H
#include "imainview.h"
#include <languageslist.h>

class MainPresenter
{
public:
    //MainPresenter(IMainView *_mainView);
    MainPresenter();
    void setView(IMainView* _mainView);
    void onTranslate();
    LanguagesList& loadLanguagesList();

private:
    IMainView *mainView;
};

#endif // MAINPRESENTER_H
