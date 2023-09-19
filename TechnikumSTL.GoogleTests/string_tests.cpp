#include "pch.h"

#include "technikumSTL/string.h"

TEST(StringTests, EqualsOne) 
{
    EXPECT_TRUE(technikum::string::one() == 1);
}