#pragma once
#include <string_view>

namespace trig
{

    constexpr std::string_view sine = "sin";
    constexpr std::string_view cosine = "cos";
    constexpr std::string_view tangent = "tan";
    constexpr std::string_view cosecant = "csc";
    constexpr std::string_view secant = "sec";
    constexpr std::string_view cotangent = "ctg";
    constexpr std::string_view arcsine = "asin";
    constexpr std::string_view arccosine = "acos";
    constexpr std::string_view arctangent = "atan";

    void start();
    float SIN(float a);
    float COS(float a);
    float TAN(float a);
    float CSC(float a);
    float SEC(float a);
    float COT(float a);
    float ASIN(float a);
    float ACOS(float a);
    float ATAN(float a);

    bool isCloseToZero(float value, float tolerance);
}