#pragma once
#include <iostream>
#include <type_traits>

template <typename T>
class printComplex {
public:
    template <typename Type, std::enable_if_t<!std::is_class_v<Type>, bool> = true>
    static void printC(Type justOneArgument)
    {
        std::cout << justOneArgument << "\n";
    }

    template <typename Type, std::enable_if_t<std::is_class_v<Type>, bool> = true>
    static void printC(Type moreThanOneValue)
    {
        for (const auto& element : moreThanOneValue) {
            std::cout << element << " ";
        }
        std::cout << "\n";
    }
};