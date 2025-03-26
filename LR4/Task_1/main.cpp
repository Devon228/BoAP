#include <iostream>
#include <gtest/gtest.h>
typedef long long ll;
typedef long double ld;

void init(short);
ld cinLongD();
ll cinLongL();
int countGreater (ll k, ld *a);

int main()
{
    ::testing::InitGoogleTest();
    RUN_ALL_TESTS();

    init(13);
    while (true)
    {
        std::cout << "Enter 1 to continue, 2 to exit\n";
        short option = (short)cinLongL();
        if (option != 1 && option != 2)
        {
            std::cout << "Incorrect input. Please, write again\n";
            continue;
        }
        if (option == 2)
        {
            std::cout << "Goodbye";
            break;
        }

        std::cout << "Enter the number of elements:\n";
        ll k = cinLongL();

        ld a[k];
        for (int i = 0; i < k; i++)
        {
            std::cout << "Enter " << i+1 << "-th element:\n";
            a[i] = cinLongD();
        }

        int num_greater = countGreater(k, a);

        std::cout << "Number of elements greater then mean is " << num_greater << "\n";
    }
    return 0;
}

int countGreater (ll k, ld *a)
{
    ld sum = 0;
    for (int i = 0; i < k; i++)
        sum += a[i];
    ld mean = sum / (ld)k;
    int num_greater = 0;
    for (int i = 0; i < k; i++)
        if (a[i] > mean)
            num_greater++;

    return num_greater;
}

void init(short variant)
{
    std::cout << "The task is to calculate the number of elements of array greater then mean value of the elements\n";
    std::cout << "Completed by Dzmitry Lukasnki, gr. 453502\n";
    if (variant != -1)
        std::cout << "Variant: " << variant << "\n";
    return;
}
ld cinLongD()
{
    ld number;

    while (!(std::cin >> number) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');

        std::cout << "Incorrect input. Please, write again\n";
    }

    return number;
}
ll cinLongL()
{
    ll number;

    while (!(std::cin >> number) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');

        std::cout << "Incorrect input. Please, write again\n";
    }

    return number;
}

TEST(countGreater, SmallTest) 
{
    ld a[1]{1};
    ASSERT_EQ(countGreater(1, a), 0);
}
