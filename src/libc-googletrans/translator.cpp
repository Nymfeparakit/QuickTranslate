#include "translator.h"
#include "Python.h"

void Translator::translate() 
{
  Py_Initialize();
  PyRun_SimpleString("from googletrans import Translator\n"
          "translator = Translator()\n"
          "print(translator.translate('Hello, world', dest='ru'))\n");
  Py_Finalize();
}
