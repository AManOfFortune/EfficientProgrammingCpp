#include "pch.h"

#include "technikumSTL/string.h"

#include <string.h>

TEST(StringTests, strlenShouldWorkForEmptyString)
{
    const char* str = "";
    ASSERT_EQ(technikum::strlen(str), strlen(str));
}

TEST(StringTests, strlenShouldWorkForNonEmptyString)
{
    const char* str = "Hello, world!";
    ASSERT_EQ(technikum::strlen(str), strlen(str));
}

TEST(StringTests, strcpyShouldWorkForEmptyString)
{
    const char* source = "";
    char target[16];
    technikum::strcpy(source, target);
    ASSERT_TRUE(strcmp(source, target) == 0);
}

TEST(StringTests, strcpyShouldWorkForNonEmptyString)
{
    const char* source = "Hello, world!";
    char target[16];
    technikum::strcpy(source, target);
    ASSERT_TRUE(strcmp(source, target) == 0);
}