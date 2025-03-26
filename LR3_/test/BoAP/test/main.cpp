#include <iostream>
using namespace std;
void getSize(int arr[])
{
    std::cout << "Size of the array from getSize(): " << sizeof(arr) << "\t";
}

int main()
{
char arr[]{ "Hello!" };
const char* ptr = arr; // ptr = 0x0000005A068FFBF4
while (*ptr)
{
    std::cout << ptr << " ";
    ++ptr;
}
//allo
}