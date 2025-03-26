#include "../header1.h"
#include <gtest/gtest.h>

int main()
{
    ::testing::InitGoogleTest();
    RUN_ALL_TESTS();
}

TEST(TestSimple, Test1)
{
    char* st = "ab";
    char *fin = "ba";
    long long res[81];
    long long num = 2;
    
    long long ans = findChain(st, fin, num, res);

    EXPECT_EQ(ans, 2);
}
TEST(TestSimple, Test2)
{
    char* st = "abcd";
    char *fin = "badc";
    long long res[81];
    long long num = 2;
    
    long long ans = findChain(st, fin, num, res);

    EXPECT_EQ(ans, 2);
}
TEST(TestSimple, Test3)
{
    char* st = "axc";
    char *fin = "xcd";
    long long res[81];
    long long num = 3;
    
    long long ans = findChain(st, fin, num, res);

    EXPECT_EQ(ans, 3);
}
TEST(TestSimple, Test4)
{
    char* st = "abdef";
    char *fin = "bcefg";
    long long res[81];
    long long num = 5;
    
    long long ans = findChain(st, fin, num, res);

    EXPECT_EQ(ans, 3);
}
TEST(TestSimple, Test5)
{
    char* st = "ab";
    char *fin = "ba";
    long long res[81];
    long long num = 2;
    
    long long ans = findChain(st, fin, num, res);

    EXPECT_EQ(ans, 2);
}
TEST(TestSimple, Test6)
{
    char* st = "zxdaghijk";
    char *fin = "xdabhijkl";
    long long res[81];
    long long num = 9;
    
    long long ans = findChain(st, fin, num, res);

    EXPECT_EQ(ans, 5);
}
TEST(TestSimple, Test7)
{
    char* st = "abdefcmnlo";
    char *fin = "bcefganloe";
    long long res[81];
    long long num = 10;
    
    long long ans = findChain(st, fin, num, res);

    EXPECT_EQ(ans, 6);
}
TEST(TestSimple, Test8)
{
    char* st = "gfabcde";
    char *fin = "egbadcf";
    long long res[81];
    long long num = 3;
    
    long long ans = findChain(st, fin, num, res);

    EXPECT_EQ(ans, 2);
}
TEST(TestExtreme, Test9)
{
    char* st = "a";
    char *fin = "a";
    long long res[81];
    long long num = 1;
    
    long long ans = findChain(st, fin, num, res);

    EXPECT_EQ(ans, 1);
}
TEST(TestSimple, Test10)
{
    char* st = "qwertyuiopasdfghjklzxcvbnm";
    char *fin = "qwertyuiopasdfghjklzxcvbnm";
    long long res[81];
    long long num = 26;
    
    long long ans = findChain(st, fin, num, res);

    EXPECT_EQ(ans, 1);
}