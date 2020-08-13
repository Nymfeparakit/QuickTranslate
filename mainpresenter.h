#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H
#include "imainview.h"

class MainPresenter
{
public:
    MainPresenter(IMainView *_mainView);
    void onTranslate();

private:
    IMainView *mainView;
};

#endif // MAINPRESENTER_H
