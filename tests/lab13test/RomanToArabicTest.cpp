//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include "ArabicRoman.h"
#include <string>

using namespace numbers;

TEST(RomanToArabic,FunctionReturnsValue){
    EXPECT_EQ(1,RomanToArabic("I"));
}

TEST(RomanToArabic,NotAcceptingCharactersOtherThanMCDLXVI){
    EXPECT_THROW(RomanToArabic("A"),std::invalid_argument);
}

TEST(RomanToArabic,ConvertsMCMTo1900){
    EXPECT_EQ(RomanToArabic("MCM"),1900);
}