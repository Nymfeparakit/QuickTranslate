#include "translator.h"
#include "Python.h"
#include <sstream>

void Translator::translate(std::string sourceText, std::string destLang, std::string sourceLang)
{
  Py_Initialize();
  PyRun_SimpleString("from googletrans import Translator\n"
          "translator = Translator()\n");
  std::ostringstream ostream;
  ostream << "print(translator.translate('" << sourceText << "', dest='ru'))\n";
  std::string tmp{ostream.str()};
  PyRun_SimpleString(tmp.c_str()); //function accepts only const char*
  //PyRun_SimpleString("print(translator.translate('Hello, world', dest='ru'))\n");
  Py_Finalize();
}
