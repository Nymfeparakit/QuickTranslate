#include "translator.h"
#include "Python.h"
#include <sstream>
#include <pyhelper.hpp>
#include <iostream>

void Translator::translate(std::string sourceText, std::string destLang, std::string sourceLang)
{
  /*
  Py_Initialize();
  PyRun_SimpleString("from googletrans import Translator\n"
          "translator = Translator()\n");
  std::ostringstream ostream;
  ostream << "print(translator.translate('" << sourceText << "', dest='ru'))\n";
  std::string tmp{ostream.str()};
  PyRun_SimpleString(tmp.c_str()); //function accepts only const char*
  Py_Finalize();
  */

    CPyInstance instance;
    CPyObject googleTransObj = PyUnicode_FromString("googletrans");
    CPyObject googletransModule = PyImport_Import(googleTransObj); // import googletrans

    if (googletransModule) {
        std::cout << "googletrans module was imported" << std::endl;
        CPyObject translatorObjCallable = PyObject_GetAttrString(googletransModule, "Translator");
        CPyObject translatorObj = PyObject_CallObject(translatorObjCallable, NULL); // get translator object
        //build args for method
        CPyObject sourceTextArg = Py_BuildValue("(s)", sourceText.c_str());
        CPyObject destLangArg = Py_BuildValue("s", "fr");
        CPyObject keywords = PyDict_New();
        PyDict_SetItemString(keywords, "dest", destLangArg);
        CPyObject translateMethod = PyObject_GetAttrString(translatorObj, "translate");
        CPyObject translatedRes = PyObject_Call(translateMethod, sourceTextArg, keywords);
        if (translatedRes) {
            std::cout << "res is not null" << std::endl;
            std::cout << PyObject_Print(translatedRes, stdout, 0) << std::endl;
        } else {
            std::cout << "res is null" << std::endl;
        }
        std::cout << PyObject_HasAttrString(translatedRes, "text");
        CPyObject textObj = PyObject_GetAttrString(translatedRes, "text");
        const char* translatedText = PyUnicode_AsUTF8(textObj);
        CPyObject destObj = PyObject_GetAttrString(translatedRes, "dest");
        const char* destLang = PyUnicode_AsUTF8(destObj);
        std::cout << translatedText << " " << destLang;
    } else {
        std::cout << "googletrans module was not imported";
    }
}
