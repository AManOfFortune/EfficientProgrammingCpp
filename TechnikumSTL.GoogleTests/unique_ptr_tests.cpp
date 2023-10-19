#include "pch.h"

#include "technikumSTL/string.h"
#include "technikumSTL/unique_ptr.h"

TEST(UniquePtrTests, EmptyInitializationShouldWork)
{
    technikum::unique_ptr<technikum::string> unique;

    ASSERT_EQ(unique.get(), nullptr);
}

TEST(UniquePtrTests, InitializationShouldWork)
{
    technikum::unique_ptr<technikum::string> unique(new technikum::string("Hello, world!"));

    ASSERT_STREQ(unique.get()->c_str(), "Hello, world!");
}

TEST(UniquePtrTests, MoveConstructorShouldWork)
{
    technikum::unique_ptr<technikum::string> unique1(new technikum::string("Hello, world!"));
    technikum::unique_ptr<technikum::string> unique2 = std::move(unique1);

    ASSERT_EQ(unique1.get(), nullptr);
    ASSERT_STREQ(unique2.get()->c_str(), "Hello, world!");
}

TEST(UniquePtrTests, MoveAssignmentShouldWork)
{
    technikum::unique_ptr<technikum::string> unique1(new technikum::string("Hallo!"));
    technikum::unique_ptr<technikum::string> unique2(new technikum::string("Servus!"));

    unique2 = std::move(unique1);

    ASSERT_EQ(unique1.get(), nullptr);
    ASSERT_STREQ(unique2.get()->c_str(), "Hallo!");
}

TEST(UniquePtrTests, ReleaseShouldReturnTheCurrentPointer)
{
    technikum::unique_ptr<technikum::string> unique(new technikum::string("Hello, world!"));
    technikum::string* returned = unique.Release();

    ASSERT_STREQ(returned->c_str(), "Hello, world!");
}

TEST(UniquePtrTests, ReleaseShouldSetInternalPointerToNullptr)
{
    technikum::unique_ptr<technikum::string> unique(new technikum::string("Hello, world!"));
    technikum::string* returned = unique.Release();

    ASSERT_EQ(unique.get(), nullptr);

    delete returned;
}

TEST(UniquePtrTests, ResetShouldSetInternalPointerToNullptr)
{
    technikum::unique_ptr<technikum::string> unique(new technikum::string("Hello, world!"));
    unique.Reset();

    ASSERT_EQ(unique.get(), nullptr);
}

TEST(UniquePtrTests, ResettingTwiceShouldWork)
{
    technikum::unique_ptr<technikum::string> unique(new technikum::string("Hello, world!"));
    unique.Reset();
    unique.Reset();

    ASSERT_EQ(unique.get(), nullptr);
}

TEST(UniquePtrTests, SwapShouldWorkWithUniquePtr)
{
    technikum::unique_ptr<technikum::string> unique1(new technikum::string("Hallo!"));
    technikum::unique_ptr<technikum::string> unique2(new technikum::string("Servus!"));

    unique1.Swap(unique2);

    ASSERT_STREQ(unique1.get()->c_str(), "Servus!");
    ASSERT_STREQ(unique2.get()->c_str(), "Hallo!");
}

TEST(UniquePtrTests, SwapShouldWorkWithPointer)
{
    technikum::unique_ptr<technikum::string> unique(new technikum::string("Hallo!"));
    technikum::string* pointer = new technikum::string("Servus!");

    unique.Swap(pointer);

    ASSERT_STREQ(unique.get()->c_str(), "Servus!");
    ASSERT_STREQ(pointer->c_str(), "Hallo!");
}

TEST(UniquePtrTests, DerefenceOperatorShouldWork)
{
    technikum::unique_ptr<int> unique(new int(1));

    ASSERT_EQ(*unique, 1);
}

TEST(UniquePtrTests, MemberAccessOperatorShouldWork)
{
    technikum::unique_ptr<technikum::string> unique(new technikum::string("Hello, world!"));

    ASSERT_STREQ(unique->c_str(), "Hello, world!");
}

TEST(UniquePtrTests, BooleanOperatorOverloadShouldEqualsTrue)
{
    technikum::unique_ptr<technikum::string> unique(new technikum::string("Hello, world!"));

    ASSERT_TRUE(unique);
}

TEST(UniquePtrTests, BooleanOperatorOverloadShouldEqualsFalse)
{
    technikum::unique_ptr<technikum::string> unique;

    ASSERT_FALSE(unique);
}

TEST(UniquePtrTests, ResetWithCustomLambdaDeleter)
{
    bool deleterCalled = false;
    auto customDeleter = [&deleterCalled](int* ptr) {
        deleterCalled = true;
        delete ptr;
        };

    technikum::unique_ptr<int, decltype(customDeleter)> unique(new int(1), customDeleter);

    unique.Reset();

    ASSERT_TRUE(deleterCalled);
}

TEST(UniquePtrTests, ResetWithDefaultDeleter)
{
    technikum::unique_ptr<int> unique(new int(1));

    unique.Reset();

    ASSERT_TRUE(unique.get() == nullptr);
}