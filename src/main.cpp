#include <iostream>
#include <map>
#include <printComplex.hpp>
#include <utility>
#include <vector>

int main()
{
    std::vector<int> v{10, 20, 30, 40};
    PrintComplex<int>{}(v);

    int num = 999;
    PrintComplex<int>{}(num);

    std::pair<std::string, int> p{"boom!", 1000};
    PrintComplex<std::string, int>{}(p);

    std::map<std::string, int> m{
        {"shalala!", 777},
        {"wow!", 111}};
    PrintComplex<std::string, int>{}(m);

    return 0;
}