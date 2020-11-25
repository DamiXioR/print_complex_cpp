#pragma once
#include <iostream>
#include <map>
#include <type_traits>
#include <utility>
#include <vector>

template <typename... T>
class PrintComplex {
public:
    template <typename Type, std::enable_if_t<std::is_class<Type>::value, bool> = true>
    void operator()(Type& moreThanOneValue) const
    {
        if constexpr (std::is_same<Type, std::vector<T...>>::value) {
            for (const auto& element : moreThanOneValue) {
                std::cout << element << " ";
            }
            std::cout << "\n";
        }
        else if constexpr (std::is_same<Type, std::pair<T...>>::value) {
            std::cout << moreThanOneValue.first << " " << moreThanOneValue.second << "\n";
        }
        else if constexpr (std::is_same<Type, std::map<T...>>::value) {
            for (const auto& [key, value] : moreThanOneValue) {
                std::cout << key << " " << value << " ";
            }
            std::cout << "\n";
        }
    }

    template <typename Type, std::enable_if_t<!std::is_class<Type>::value, bool> = true>
    void operator()(Type& justOneArgument) const
    {
        std::cout << justOneArgument << "\n";
    }
};