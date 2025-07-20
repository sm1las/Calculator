#pragma once
#include <string_view>

namespace quadratic
{

    constexpr std::string_view D = "d";
    constexpr std::string_view ROOTS = "roots";
    constexpr std::string_view X0 = "x0";
    constexpr std::string_view Y0 = "y0";

    void start();
    void formatter(float a, float b, float c);
    float discriminant(float a, float b, float c);
    float roots(float a, float b, float c);
    float x0(float a, float b);
    float y0(float a, float b, float c);
}