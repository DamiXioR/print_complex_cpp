#include <iostream>
#include <printComplex.hpp>
#include <vector>

int main()
{
    PrintComplex printComplex;
    std::vector<int> v {10,20,30,40};
    printComplex(v);

    int num = 999;
    printComplex(num);

    return 0;
}