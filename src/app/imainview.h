#ifndef IMAINVIEW_H
#define IMAINVIEW_H
#include <string>
#include <map>

// interface that should be implemented by the view interacting with presenter
class IMainView
{
public:
    virtual void setSourceText(std::string sourceText) = 0;
    virtual std::string getSourceText() = 0; //get text that should be translated
    virtual std::string getSourceLanguage() = 0;
    virtual std::string getDestLanguage() = 0; // get language to translate to
    virtual void showTranslatedText(std::string text) = 0; // show in view translated text
    virtual void setTranslatedText(std::string text) = 0;
    virtual std::string getTranslatedText() = 0; // get last translated text
    virtual std::string getClipboardText() = 0;
    virtual std::string showBusyIndicator() = 0;
};

#endif // IMAINVIEW_H
