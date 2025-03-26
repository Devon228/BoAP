#include <iostream>
#include <gtest/gtest.h>
typedef long long ll;
typedef long double ld;

void init(short);
ld cinLongD();
ll cinLongL();
ld findSum(ld **a, ll n);

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

        std::cout << "Enter the size of matrix\n";
        ll n = cinLongL();

        ld **a = new ld*[n];
        for (int i = 0; i < n; i++)
            a[i] = new ld[n];
    
        std::cout << "Enter n strings with n elements in each\n";
        for (int i = 0; i < n; i++)
        {
            while (true)
            {
                bool err = 0;

                for (int j = 0; j < n; j++)
                    if (!(std::cin >> a[i][j]))
                    {
                        err = 1;
                        std::cin.clear();
                        while (std::cin.get() != '\n');
                        std::cout << "Incorrect input. Please, write the last string again\n";
                        break;
                    }
                
                if (std::cin.peek() != '\n')
                {
                    err = 1;
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    std::cout << "Incorrect input. Please, write the last string again\n";              
                }

                if (!err)
                    break;
            }
        }

        ld sum = findSum(a, n);

        for (int i = 0; i < n; i++)
        {
            delete[] a[i];
            a[i] = nullptr;
        }
        delete[] a;
        a = nullptr;
        std::cout << "Sum of some special elements is " << sum << "\n";
    }
    return 0;
}

ld findSum (ld **a, ll n)
{
    ld sum = 0;
    for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
        {
            if (i < n / 2 && j > i && j + i < n - 1)
                sum += a[i][j];
            if (i > n / 2 && j < i && j + i > n - 1)
                sum += a[i][j];
        }

    return sum;
}
void init(short variant)
{
    std::cout << "The task is to calculate the sum of some special  elements of the square matrix\n";
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
    ld **a = new ld*[5];
    for (int i = 0; i < 5; i++)
        a[i] = new ld[5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            a[i][j] = i * 5 + j;

    ASSERT_EQ(findSum(a, 5), 96);
    for (int i = 0; i < 5; i++)
    {
        delete[] a[i];
        a[i] = nullptr;
    }
    delete[] a;
    a = nullptr;
}
