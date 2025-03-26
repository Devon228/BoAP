#include "../header1.h"
#include <gtest/gtest.h>

int main()
{
    ::testing::InitGoogleTest();
    RUN_ALL_TESTS();
}

TEST(TestSimple, Test1)
{
    char* str = "aaaaaaaaaaa";
    char* symb = new char[257];
    decompose(str, symb);

    EXPECT_STREQ(symb, "a");
}
TEST(TestSimple, Test2)
{
    char* str = "AEGIS";
    char* symb = new char[257];
    decompose(str, symb);

    EXPECT_STREQ(symb, "AEGIS");
}
TEST(TestSimple, Test3)
{
    char* str = "���� ����";
    char* symb = new char[257];
    decompose(str, symb);

    EXPECT_STREQ(symb, "���� ");
}
TEST(TestSimple, Test4)
{
    char* str = "������ � � � ��@@ls;";
    char* symb = new char[257];
    decompose(str, symb);

    EXPECT_STREQ(symb, "��� �@ls;");
}
TEST(TestSimple, Test5)
{
    char* str = "+++---***";
    char* symb = new char[257];
    decompose(str, symb);

    EXPECT_STREQ(symb, "+-*");
}
TEST(TestSimple, Test6)
{
    char* str = "�g";
    char* symb = new char[257];
    decompose(str, symb);

    EXPECT_STREQ(symb, "�g");
}
TEST(TestSimple, Test7)
{
    char* str = "09876543231";
    char* symb = new char[257];
    decompose(str, symb);

    EXPECT_STREQ(symb, "0987654321");
}
TEST(TestSimple, Test8)
{
    char* str = "(((((((((((((((((((((((((((())))))))))))))))))))))))))))";
    char* symb = new char[257];
    decompose(str, symb);

    EXPECT_STREQ(symb, "()");
}
TEST(TestExtreme, Test9)
{
    char* str = "%�a";
    char* symb = new char[257];
    decompose(str, symb);

    EXPECT_STREQ(symb, "%�a");
}
TEST(TestSimple, Test10)
{
    char* str = "   |                                                              ";
    char* symb = new char[257];
    decompose(str, symb);

    EXPECT_STREQ(symb, " |");
}