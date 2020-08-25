#ifndef IMAINVIEW_H
#define IMAINVIEW_H
#include <string>
#include <map>

class IMainView
{
public:
    virtual void setSourceText(std::string sourceText) = 0;
    virtual std::string getSourceText() = 0;
    virtual std::string getSourceLanguage() = 0;
    virtual std::string getDestLanguage() = 0;
    virtual void showTranslatedText(std::string text) = 0;
    virtual void setTranslatedText(std::string text) = 0;
    virtual std::string getTranslatedText() = 0;
    virtual void showWelcomeWindow() = 0;
    virtual void showMainWindow() = 0;
    virtual void showOnlyTranslatedTextWindow() = 0;
    virtual std::string getClipboardText() = 0;
    virtual std::string showBusyIndicator() = 0;
};

#endif // IMAINVIEW_H
