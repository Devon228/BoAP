#include <iostream>
#include <gtest/gtest.h>
typedef long long ll;
typedef long double ld;

void init(short);
ld cinLongD();
ll cinLongL();
ll findSum(ll, ll, int *a);

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

        std::cout << "Enter the number of strings\n";
        ll m = cinLongL();
        std::cout << "Enter the number of columns\n";
        ll n = cinLongL();

        int a[m][n];
    
        ll sum = findSum(m, n, *a);

        std::cout << "Sum of elements from strings with even number is " << sum << "\n";
    }
    return 0;
}

ll findSum (ll m, ll n, int *a)
{
    ll sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << a[m*i+j] << " ";
        std::cout << "\n";
    }
    for (int i = 0; i < m; i += 2)
        for (int j = 0; j < n; j++)
            sum += a[m*i+j];

    return sum;
}
void init(short variant)
{
    std::cout << "The task is to calculate the sum of elements from strings with even number\n";
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
TEST(findSum, SmallTest) 
{
    int a[3][3] = { 
        {1, 228, 0},
        {-3, -234232342, 2},
        {123123, -55858, -1213212}
    };
    ASSERT_EQ(findSum(3, 3, *a), -1145718);
}
