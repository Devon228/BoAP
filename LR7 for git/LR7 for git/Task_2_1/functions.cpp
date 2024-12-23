#include "header.h"

void init(short variant)
{
    std::cout << "\n";
    std::cout << "Выполнено Дмитрием Луканским, гр. 43502\n";
    if (variant != -1)
        std::cout << "Вариант: " << variant << "\n";
    return;
}

void cinLong(ll& number)
{
    while (!(std::cin >> number) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');

        std::cout << "Неверный ввод. Введите заново\n";
    }
}

std::string makeEq(std::string& num, int k) //O(n)
{
    if (k == 0) 
       return num;

    num.insert(1, k, '0');  
    return num;
}

std::string toDop(const std::string& num) //O(n)
{
    if (num[0] != '1') 
    {
        return num;
    }

    std::string inv = num;
    for (int i = 1; i < inv.size(); i++)
    {
        inv[i] = (inv[i] == '0') ? '1' : '0';
    }

    int plus = 1;
    for (int i = inv.size() - 1; i >= 1; i--) //O(n)
    {
        if (inv[i] == '1' && plus == 1)
        {
            inv[i] = '0';
        } 
        else
        {
            inv[i] += plus;
            plus = 0;
        }
    }

    return inv;
}

std::string sum(const std::string& num1, const std::string& num2) //O(n)
 {
    std::string res(num1);
    int plus = 0;

    for (int i = num1.size() - 1; i >= 0; --i)  //O(n)
    {
        if (num1[i] == '0' && num2[i] == '0' && plus == 0)
        {
            res[i] = '0';
        }
        else if ((num1[i] == '1' && num2[i] == '1' && plus == 0) ||
                 (num1[i] == '1' && num2[i] == '0' && plus == 1) ||
                 (num1[i] == '0' && num2[i] == '1' && plus == 1)) 
        {
            res[i] = '0';
            plus = 1;
        }
        else if ((num1[i] == '1' && num2[i] == '0' && plus == 0) ||
                 (num1[i] == '0' && num2[i] == '0' && plus == 1) ||
                 (num1[i] == '0' && num2[i] == '1' && plus == 0))
        {
            res[i] = '1';
            plus = 0;
        }
        else
        {
            res[i] = '1';
            plus = 1;
        }
    }

    return res;
}

std::string toPr(std::string num) //O(n)
{
    if (num[0] == '0') 
        return num;

    for (int i = num.size() - 1; i > 0; --i) //O(n)
    {
        if (num[i] == '0') 
            num[i] = '1';
        if (num[i] == '1') 
        {
            num[i] = '0';
            break;
        }
    }

    std::string inv = num;
    for (int i = 1; i < inv.size(); ++i) //O(n)
        inv[i] = (inv[i] == '0') ? '1' : '0';

    return inv;
}