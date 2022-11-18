#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    const int n = 5;
    Array<int> numbers(n);
    int* mirror = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < n; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[n] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < n; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

    std::cout << numbers << std::endl;
    
    return 0;
}