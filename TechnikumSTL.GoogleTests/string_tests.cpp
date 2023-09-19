#include "pch.h"

#include "technikumSTL/string.h"

#include <string.h>
#include <iostream>

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

TEST(StringTests, lengthShouldBeZero)
{
    technikum::string s;
    ASSERT_EQ(s.length(), 0);
}

TEST(StringTests, lengthShouldBeSix)
{
    technikum::string s("Hello!");
    ASSERT_EQ(s.length(), 6);
}

TEST(StringTests, lengthShouldBeThirteen)
{
    technikum::string helloWorld("Hello, world!");
    technikum::string s(helloWorld);
    ASSERT_EQ(s.length(), 13);
}

TEST(StringTests, sizeShouldBeZero)
{
    technikum::string s;
    ASSERT_EQ(s.size(), 0);
}

TEST(StringTests, sizeShouldBeSix)
{
    technikum::string s("Hello!");
    ASSERT_EQ(s.size(), 6);
}

TEST(StringTests, sizeShouldBeThirteen)
{
    technikum::string helloWorld("Hello, world!");
    technikum::string s(helloWorld);
    ASSERT_EQ(s.size(), 13);
}

TEST(StringTests, c_strShouldBeEmpty)
{
    technikum::string s;
    const char* other = "";
    ASSERT_TRUE(strcmp(s.c_str(), other) == 0);
}

TEST(StringTests, c_strShouldEqualCString)
{
    technikum::string s("Hello, world!");
    const char* other = "Hello, world!";
    ASSERT_TRUE(strcmp(s.c_str(), other) == 0);
}

TEST(StringTests, c_strShouldEqualOtherString)
{
    technikum::string s("Hello, world!");
    technikum::string other("Hello, world!");
    ASSERT_TRUE(strcmp(s.c_str(), other.c_str()) == 0);
}

TEST(StringTests, capacityShouldBeOne)
{
    technikum::string s;
    ASSERT_EQ(s.capacity(), 1);
}

TEST(StringTests, capacityShouldBeSeven)
{
    technikum::string s("Hello!");
    ASSERT_EQ(s.capacity(), 7);
}

TEST(StringTests, capacityShouldBeFourteen)
{
    technikum::string helloWorld("Hello, world!");
    technikum::string s(helloWorld);
    ASSERT_EQ(s.capacity(), 14);
}

TEST(StringTests, capacityShouldBeFiveAfterReserve)
{
    technikum::string s;
    s.reserve(4);
    ASSERT_EQ(s.capacity(), 5);
}

TEST(StringTests, capacityShouldBeFiveAfterMultipleReserves)
{
    technikum::string s;
    s.reserve(10);
    s.reserve(4);
    ASSERT_EQ(s.capacity(), 5);
}

TEST(StringTests, c_strShouldStayTheSameAfterReserve)
{
    technikum::string s("Hello!");
    s.reserve(10);
    ASSERT_TRUE(strcmp(s.c_str(), "Hello!") == 0);
}

TEST(StringTests, c_strShouldStayTheSameAfterMultipleReserves)
{
    technikum::string s("Hello!");
    s.reserve(10);
    s.reserve(3);
    s.reserve(8);
    ASSERT_TRUE(strcmp(s.c_str(), "Hello!") == 0);
}

TEST(StringTests, appendShouldWorkForEmptyString)
{
    technikum::string s("a");
    s.append("");
    ASSERT_TRUE(strcmp(s.c_str(), "a") == 0);
}

TEST(StringTests, appendShouldWorkForNonEmptyString)
{
    technikum::string s("a");
    s.append("b");
    ASSERT_TRUE(strcmp(s.c_str(), "ab") == 0);
}