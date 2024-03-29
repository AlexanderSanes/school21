#include "iter.hpp"

int main()
{
    const int N = 5;
    int arr1[] = { 1, 2, 3, 4, 5 };

    std::cout << "arr1: ";
    iter(arr1, N, &print);

    double arr2[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    std::cout << "\narr2: ";
    iter(arr2, N, &print);

    char arr3[] = { 'a', 'b', 'c', 'd', 'e' };

    std::cout << "\narr3: ";
    iter(arr3, N, &print);

    std::string arr4[] = { "one", "two", "three", "four", "five" };

    std::cout << "\narr4: ";
    iter(arr4, N, &print);

    return 0;
}
