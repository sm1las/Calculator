#pragma once
#include <string_view>

namespace single
{

    constexpr std::string_view SROOT = "sr";
    constexpr std::string_view CROOT = "cr";
    constexpr std::string_view SQUARE = "s";
    constexpr std::string_view CUBE = "c";
    constexpr std::string_view FACTORIAL = "f";

    void start();
    float sroot(float a);
    float croot(float a);
    float square(float a);
    float cube(float a);
    long factorial(float a);

    bool isInteger(float number);
}