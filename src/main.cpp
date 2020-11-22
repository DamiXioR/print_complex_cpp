#include <iostream>
#include <printComplex.hpp>
#include <vector>

int main()
{
    std::vector<int> v {10,20,30,40};
    printComplex<std::vector<int>>::printC(v);

    int num = 999;
    printComplex<std::vector<int>>::printC(num);

    return 0;
}