#pragma once
#include <iostream>
#include <type_traits>

class printComplex {
public:
    template <typename Type, std::enable_if_t<std::is_class<Type>::value, bool> = true>
    printComplex& operator()(Type moreThanOneValue)
    {
        for (const auto& element : moreThanOneValue) {
            std::cout << element << " ";
        }
        std::cout << "\n";
        return *this;
    }

    template <typename Type, std::enable_if_t<!std::is_class<Type>::value, bool> = true>
    printComplex& operator()(Type justOneArgument)
    {
        std::cout << justOneArgument << "\n";
        return *this;
    }
};