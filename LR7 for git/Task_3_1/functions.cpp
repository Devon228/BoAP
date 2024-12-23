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


std::string makeAlpha(int base) 
{  
    std::string alphabet;

    for (int i = 0; i < 10 && alphabet.size() < base; ++i)  //
        alphabet += ('0' + i);

    for (int i = 0; i < 26 && alphabet.size() < base; ++i)  //
        alphabet += ('A' + i);

    for (int i = 0; i < 26 && alphabet.size() < base; ++i)  //
        alphabet += ('a' + i);

    return alphabet;
}

int charToVal(char c, const std::string& alphabet) //
{  
    return alphabet.find(c);  // 
}

char valToChar(int value, const std::string& alphabet) 
{
    return alphabet[value];
}

std::string zero(const std::string& num, int newLength) //
{  
    std::string result = num;

    for (int i = 0; i < newLength - num.length(); ++i) //
    { 
        result = '0' + result;
    }

    return result;
}

std::string add(std::string& num1, std::string& num2, const std::string& alphabet) //O(n)
 {  
    if (num1[0] == '-') 
        num1.erase(0, 1);  // O(n)
    if (num2[0] == '-') 
        num2.erase(0, 1);  // O(n)

    int maxLength = std::max(num1.length(), num2.length());
    num1 = zero(num1, maxLength);  // O(n)
    num2 = zero(num2, maxLength);  // O(n)
    int base = alphabet.size();
    std::string result;
    int carry = 0;
    for (int i = num1.size() - 1; i >= 0; --i) //O(n)
    {  
        int promegh = charToVal(num1[i], alphabet) + charToVal(num2[i], alphabet) + carry;

        if (promegh < base) {
            result += valToChar(promegh, alphabet);
            carry = 0;
        }
        else {
            result += valToChar(promegh - base, alphabet);
            carry = 1;
        }
    }
    if (carry == 1) {
        result += '1';
    }
    reverse(result.begin(), result.end());  // O(n)
    return result;
}

bool bigger(const std::string& num1, const std::string& num2, const std::string& alphabet, int i) //
{  
    if (i == num1.size()) {
        return true;
    }

    if (charToVal(num1[i], alphabet) > charToVal(num2[i], alphabet)) 
        return true;
    else if (charToVal(num1[i], alphabet) < charToVal(num2[i], alphabet)) 
        return false;
    else
        return bigger(num1, num2, alphabet, i + 1);  // O(n)
}

std::string minus(std::string& num1, std::string& num2, const std::string& alphabet) //O(n)
{  
    if (num1[0] == '-') 
        num1.erase(0, 1);  // O(n)
    
    if (num2[0] == '-') 
        num2.erase(0, 1);  // O(n)
    
    int maxLength = std::max(num1.length(), num2.length());
    num1 = zero(num1, maxLength);  // O(n)
    num2 = zero(num2, maxLength);  // O(n)
    int base = alphabet.size();
    std::string result, first, second;
    int carry = 0;

    if (bigger(num1, num2, alphabet, 0)) 
    {
        first = num1;
        second = num2;
        result += '+';
    }
    else 
    {
        first = num2;
        second = num1;
        result += '-';
    }

    for (int i = first.size() - 1; i >= 0; --i) //O(n)
    {  
        int promegh = charToVal(first[i], alphabet) - charToVal(second[i], alphabet) - carry;

        if (promegh < 0) {
            result += valToChar(promegh + base, alphabet);
            carry = 1;
        }
        else {
            result += valToChar(promegh, alphabet);
            carry = 0;
        }
    }

    std::reverse(result.begin() + 1, result.end());  // O(n)
    return result;
}