#include <gtest/gtest.h>
//#include <gmock/gmock-matchers.h>
//#include "googletranslator.h"
#include "translator.h"

using namespace testing;

TEST(GoogleTranslatorTests, TranslateWordToRussianCorrectly)
{
    Translator t;

    std::string translatedRes = t.translate("Hello", "ru", "en");

    EXPECT_EQ(translatedRes, "Привет");
}

TEST(GoogleTranslatorTests, TranslateSentenceToEnglishCorrectly)
{
    Translator t;

    std::string translatedRes = t.translate(
                "Google — крупнейшая в мире поисковая система интернета, принадлежащая корпорации Google Inc.",
                "en",
                "ru");

    EXPECT_EQ(translatedRes, "Google is the world's largest Internet search engine owned by Google Inc.");

}
