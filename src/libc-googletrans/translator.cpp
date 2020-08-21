#include "translator.h"
#include <Python.h>
#include <sstream>
#include <pyhelper.hpp>
#include <iostream>

std::string Translator::translate(std::string sourceText, std::string destLang, std::string sourceLang)
{

    CPyInstance instance;
    CPyObject googleTransObj = PyUnicode_FromString("googletrans");
    CPyObject googletransModule = PyImport_Import(googleTransObj); // import googletrans

    if (googletransModule) {
        CPyObject translatorObjCallable = PyObject_GetAttrString(googletransModule, "Translator");
        CPyObject translatorObj = PyObject_CallObject(translatorObjCallable, NULL); // get translator object
        //build args for method
        CPyObject sourceTextArg = Py_BuildValue("(s)", sourceText.c_str());
        CPyObject destLangArg = Py_BuildValue("s", destLang.c_str());
        CPyObject keywords = PyDict_New();
        PyDict_SetItemString(keywords, "dest", destLangArg);
        CPyObject translateMethod = PyObject_GetAttrString(translatorObj, "translate");
        CPyObject translatedRes = PyObject_Call(translateMethod, sourceTextArg, keywords);
        CPyObject textObj = PyObject_GetAttrString(translatedRes, "text");
        const char* translatedText = PyUnicode_AsUTF8(textObj);
        return translatedText;
    } else {
        return "";
    }

}

std::map<std::string, std::string> Translator::getSupportedLanguagesNamesAndCodes()
{
   CPyInstance instance;
   CPyObject googleTransObj = PyUnicode_FromString("googletrans");
   CPyObject googletransModule = PyImport_Import(googleTransObj); // import googletrans

   std::map<std::string, std::string> languagesMap;
   if (googletransModule) {
       CPyObject languagesDictObj = PyObject_GetAttrString(googletransModule, "LANGUAGES");
       PyObject *key, *value;
       Py_ssize_t pos = 0;

       while(PyDict_Next(languagesDictObj, &pos, &key, &value)) {
           std::string langCode = PyUnicode_AsUTF8(key);
           std::string langName = PyUnicode_AsUTF8(value);
           languagesMap.insert(std::pair<std::string, std::string>(langName, langCode));
       }
   }

   return languagesMap;
}
