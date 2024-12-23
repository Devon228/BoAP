#include <iostream>
#include <string>
#include <algorithm>

typedef long long ll;

void init(short variant);
void cinLong(ll& number);
std::string makeAlpha(int base);
int charToVal(char c, const std::string& alphabet);
char valToChar(int value, const std::string& alphabet);
std::string zero(const std::string& num, int newLength);
std::string add(std::string& num1, std::string& num2, const std::string& alphabet);
bool bigger(const std::string& num1, const std::string& num2, const std::string& alphabet, int i);
std::string minus(std::string& num1, std::string& num2, const std::string& alphabet);