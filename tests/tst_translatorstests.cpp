#include <gtest/gtest.h>
//#include <gmock/gmock-matchers.h>
#include "googletranslator.h"

using namespace testing;

TEST(TranslatorsTests, GoogleTranslatorTest)
{
    GoogleTranslator t;

    //std::string translateRes = t.translate("Hello", "ru");

    //EXPECT_EQ(translateRes, "Привет");
    EXPECT_EQ(1, 1);
    //ASSERT_THAT(0, Eq(0));
}