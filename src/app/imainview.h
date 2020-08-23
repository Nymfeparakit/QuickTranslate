#ifndef IMAINVIEW_H
#define IMAINVIEW_H
#include <string>
#include <map>

class IMainView
{
public:
    virtual std::string getSourceText() = 0;
    virtual std::string getSourceLanguage() = 0;
    virtual std::string getDestLanguage() = 0;
    virtual void showTranslatedText(std::string text) = 0;
    virtual void showSupportedLangsList(std::map<std::string, std::string>) = 0;
    virtual void showWelcomeWindow() = 0;
    virtual void showMainWindow() = 0;
    virtual std::string getClipboardText() = 0;
};

#endif // IMAINVIEW_H
