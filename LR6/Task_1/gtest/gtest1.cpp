#include "../header1.h"
#include <gtest/gtest.h>

int main()
{
    ::testing::InitGoogleTest();
    RUN_ALL_TESTS();
}

TEST(TestSimple, Test1)
{
    char* str = "aboba beb Dfgdfg AEGIS";
    short num = -1, ind = -1;
    findMaxLenWord(str, num, ind);

    EXPECT_EQ(num, 3);
    EXPECT_EQ(ind, 10);
}
TEST(TestSimple, Test2)
{
    char* str = "AEGIS";
    short num = -1, ind = -1;
    findMaxLenWord(str, num, ind);

    EXPECT_EQ(num, 1);
    EXPECT_EQ(ind, 0);
}
TEST(TestSimple, Test3)
{
    char* str = " абобус аова ва";
    short num = -1, ind = -1;
    findMaxLenWord(str, num, ind);

    EXPECT_EQ(num, 1);
    EXPECT_EQ(ind, 1);
}
TEST(TestSimple, Test4)
{
    char* str = "привет прива прив приветикии ";
    short num = -1, ind = -1;
    findMaxLenWord(str, num, ind);

    EXPECT_EQ(num, 4);
    EXPECT_EQ(ind, 18);
}
TEST(TestSimple, Test5)
{
    char* str = "   aboba    beb   Dfgdfg   AEGIS  ";
    short num = -1, ind = -1;
    findMaxLenWord(str, num, ind);

    EXPECT_EQ(num, 3);
    EXPECT_EQ(ind, 18);
}
TEST(TestSimple, Test6)
{
    char* str = "          ab     ";
    short num = -1, ind = -1;
    findMaxLenWord(str, num, ind);

    EXPECT_EQ(num, 1);
    EXPECT_EQ(ind, 10);
}
TEST(TestSimple, Test7)
{
    char* str = "abobasdf beb Dfgdfg AEGIS and abbus mega";
    short num = -1, ind = -1;
    findMaxLenWord(str, num, ind);

    EXPECT_EQ(num, 1);
    EXPECT_EQ(ind, 0);
}
TEST(TestSimple, Test8)
{
    char* str = "aboba bebraarsrser SDFDFSFD  asfg adrgagsd arggaerf Dfgdfg AEGIS";
    short num = -1, ind = -1;
    findMaxLenWord(str, num, ind);

    EXPECT_EQ(num, 2);
    EXPECT_EQ(ind, 6);
}
TEST(TestExtreme, Test9)
{
    char* str = "             ";
    short num = -1, ind = -1;
    findMaxLenWord(str, num, ind);

    EXPECT_EQ(num, -1);
    EXPECT_EQ(ind, -1);
}
TEST(TestSimple, Test10)
{
    char* str = "?";
    short num = -1, ind = -1;
    findMaxLenWord(str, num, ind);

    EXPECT_EQ(num, 1);
    EXPECT_EQ(ind, 0);
}