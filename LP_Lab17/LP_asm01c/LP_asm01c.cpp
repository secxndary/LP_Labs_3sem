#include <iostream>

extern "C" 
{
    int __stdcall getmin(int x[], int y);
    int __stdcall getmax(int x[], int y);
};

int main()
{
    int arr[] = { 12, 5, 100, 1, 2, 3, 12, 14, 9, 7 };
    std::cout << "getmin - getmax = " << getmax(arr, 10) - getmin(arr, 10) << std::endl;
    return 0;
}
