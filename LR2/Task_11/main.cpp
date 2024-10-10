#include <iostream>

int main()
{
    long long h1, min1, h2, min2;
    std::cout << "Enter h1, min1\n";
    std::cin >> h1 >> min1;
    std::cout << "Enter h2, min2\n";
    std::cin >> h2 >> min2;

    long long time = 0;
    if (h2 > h1)
    {
        time += (60 - min1) + min2;
        if (h2 - h1 > 1) 
            time += (h2 - h1 - 1) * 60;
    }
    else if (h1 == h2)
    {
        if (min1 <= min2)
            time += min2 - min1;
        else
            time += 24 * 60 - (min1 - min2);
    }
    else //h1 > h2
    {
        time += 24 * 60 - (60 - min2) - min1;
        if (h1 - h2 > 1)
            time -= (h1 - h2 - 1) * 60;
    }

    std::cout << (time / 60) << " hours and " << (time % 60) << " minutes.";
    return 0;
}