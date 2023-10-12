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

TEST(StringTests, capacityShouldBeMinimumCapacity)
{
    technikum::string s;
    ASSERT_EQ(s.capacity(), technikum::string::kMinimumCapacity);
}

TEST(StringTests, capacityShouldBeTwenty)
{
    technikum::string s("Lorem ipsum gravida");
    ASSERT_EQ(s.capacity(), 20);
}

TEST(StringTests, capacityShouldBeTwentyone)
{
    technikum::string helloWorld("Lorem ipsum gravida.");
    technikum::string s(helloWorld);
    ASSERT_EQ(s.capacity(), 21);
}

TEST(StringTests, capacityShouldBeMinimumCapacityAfterReserve)
{
    technikum::string s;
    s.reserve(4);
    ASSERT_EQ(s.capacity(), technikum::string::kMinimumCapacity);
}

TEST(StringTests, capacityShouldUpdateAfterReserve)
{
    technikum::string s;
    s.reserve(20);
    ASSERT_EQ(s.capacity(), 20);
}

TEST(StringTests, capacityShouldUpdateAfterMultipleReserves)
{
    technikum::string s;
    s.reserve(24);
    s.reserve(32);
    ASSERT_EQ(s.capacity(), 32);
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
    s.append("c");
    ASSERT_TRUE(strcmp(s.c_str(), "abc") == 0) << " - Recieved string: \"" << s << "\"";
}

TEST(StringTests, appendShouldWorkWhenChaining)
{
    technikum::string s("a");
    s.append("b").append("c");
    
    ASSERT_TRUE(strcmp(s.c_str(), "abc") == 0) << " - Recieved string: \"" << s << "\"";
}

TEST(StringTests, copyConstructorShouldWorkOnStack)
{
    technikum::string s1("Hello");
    technikum::string s2(s1);
    ASSERT_TRUE(strcmp(s2.c_str(), "Hello") == 0);
}

TEST(StringTests, copyConstructorShouldWorkOnHeap)
{
    technikum::string s1("Hello");
    technikum::string* s2 = new technikum::string(s1);
    ASSERT_TRUE(strcmp(s2->c_str(), "Hello") == 0);

    delete s2;
}

TEST(StringTests, copyAssignmentOperatorShouldWork)
{
    technikum::string s1("Hello");
    technikum::string s2("World");
    s2 = s1;
    ASSERT_TRUE(strcmp(s2.c_str(), "Hello") == 0);
}

TEST(StringTests, copyAssignmentOperatorShouldNotCopySameObject)
{
    technikum::string s1("Hello");
    s1 = s1;
    ASSERT_TRUE(strcmp(s1.c_str(), "Hello") == 0);
}

TEST(StringTests, moveConstructorShouldWork)
{
    technikum::string s1("Hello");
    technikum::string s2 = std::move(s1);

    ASSERT_TRUE(s1.c_str() == nullptr);
    ASSERT_TRUE(strcmp(s2.c_str(), "Hello") == 0);
}

TEST(StringTests, moveAssignmentOperatorShouldWork)
{
    technikum::string s1("Hello");
    technikum::string s2("World");

    s2 = std::move(s1);

    ASSERT_TRUE(s1.c_str() == nullptr);
    ASSERT_TRUE(strcmp(s2.c_str(), "Hello") == 0);
}

TEST(StringTests, additionAssignmentOperatorShouldConcatenateTwoEmptyStrings)
{
    technikum::string s1("");
    technikum::string s2("");

    s1 += s2;
    
    ASSERT_TRUE(strcmp(s1.c_str(), "") == 0);
}

TEST(StringTests, additionAssignmentOperatorShouldConcatenateWithOneEmptyString)
{
    technikum::string s1("Hello!");
    technikum::string s2("");

    s1 += s2;

    ASSERT_TRUE(strcmp(s1.c_str(), "Hello!") == 0);
}

TEST(StringTests, additionAssignmentOperatorShouldConcatenateTwoStrings)
{
    technikum::string s1("Hello, ");
    technikum::string s2("world!");

    s1 += s2;

    ASSERT_TRUE(strcmp(s1.c_str(), "Hello, world!") == 0);
}

TEST(StringTests, additionAssignmentOperatorShouldConcatenateWithEmptyConstCharArray)
{
    technikum::string s1("Hello!");
    const char* s2 = "";

    s1 += s2;

    ASSERT_TRUE(strcmp(s1.c_str(), "Hello!") == 0);
}

TEST(StringTests, additionAssignmentOperatorShouldConcatenateWithConstCharArray)
{
    technikum::string s1("Hello, ");
    const char* s2 = "world!";

    s1 += s2;

    ASSERT_TRUE(strcmp(s1.c_str(), "Hello, world!") == 0);
}

TEST(StringTests, additionOperatorShouldConcatenateTwoEmptyStrings)
{
    technikum::string s1("");
    technikum::string s2("");

    technikum::string s3 = s1 + s2;

    ASSERT_TRUE(strcmp(s3.c_str(), "") == 0);
}

TEST(StringTests, additionOperatorShouldConcatenateWithOneEmptyString)
{
    technikum::string s1("Hello!");
    technikum::string s2("");

    technikum::string s3 = s1 + s2;

    ASSERT_TRUE(strcmp(s3.c_str(), "Hello!") == 0);
}

TEST(StringTests, additionOperatorShouldConcatenateTwoStrings)
{
    technikum::string s1("Hello, ");
    technikum::string s2("world!");

    technikum::string s3 = s1 + s2;

    ASSERT_TRUE(strcmp(s3.c_str(), "Hello, world!") == 0);
}

TEST(StringTests, additionOperatorShouldNotAffectLeftHandSideString)
{
    technikum::string s1("Hello, ");
    technikum::string s2("world!");

    technikum::string s3 = s1 + s2;

    ASSERT_TRUE(strcmp(s1.c_str(), "Hello, ") == 0);
}

TEST(StringTests, additionOperatorShouldConcatenateWithOneEmptyConstCharArray)
{
    technikum::string s1("Hello!");
    const char* s2 = "";

    technikum::string s3 = s1 + s2;

    ASSERT_TRUE(strcmp(s3.c_str(), "Hello!") == 0);
}

TEST(StringTests, additionOperatorShouldConcatenateWithOneConstCharArray)
{
    technikum::string s1("Hello, ");
    const char* s2 = "world!";

    technikum::string s3 = s1 + s2;

    ASSERT_TRUE(strcmp(s3.c_str(), "Hello, world!") == 0);
}

TEST(StringTests, additionOperatorShouldNotAffectLeftHandSideString2)
{
    technikum::string s1("Hello, ");
    const char* s2 = "world!";

    technikum::string s3 = s1 + s2;

    ASSERT_TRUE(strcmp(s1.c_str(), "Hello, ") == 0);
}

TEST(StringTests, constCharArrayCastOperatorShouldWork)
{
    technikum::string s("Hello, world!");

    ASSERT_TRUE(strcmp(s, "Hello, world!") == 0);
}

TEST(StringTests, IteratorBeginShouldWork) {
    technikum::string s("Hello, world!");
    technikum::string::Iterator it = s.begin();

    ASSERT_EQ(*it, 'H');
}

TEST(StringTests, IteratorEndShouldWork) {
    technikum::string s("Hello, world!");
    technikum::string::Iterator it = s.end();

    ASSERT_EQ(*it, '\0');
}


TEST(StringTests, IteratorIncrementShouldWork) {
    technikum::string s("Hello, world!");
    technikum::string::Iterator it = s.begin();

    ++it;
    ASSERT_EQ(*it, 'e');
    it++;
    ASSERT_EQ(*it, 'l');
}

TEST(StringTests, IteratorEqualityShouldWork) {
    technikum::string s("Hello, world!");
    technikum::string::Iterator it1 = s.begin();
    technikum::string::Iterator it2 = s.begin();

    ASSERT_EQ(it1, it2);
    ++it1;
    ASSERT_NE(it1, it2);
}

TEST(StringTests, IteratorIterationShouldWork) {
    technikum::string s("Hello, world!");
    technikum::string::Iterator it = s.begin();
    std::string result;

    while (it != s.end()) {
        result += *it;
        ++it;
    }

    ASSERT_EQ(result, "Hello, world!");
}

TEST(StringTests, IteratorSearchShouldWork) {
    technikum::string s("Hello, world!");

    technikum::string::Iterator it = std::find(s.begin(), s.end(), 'o');

    ASSERT_NE(it, s.end());
    ASSERT_EQ(*it, 'o');
}
