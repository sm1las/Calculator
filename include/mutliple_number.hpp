#pragma once

#include <string_view>
#include <vector>

namespace multiple
{

    constexpr std::string_view ADD = "add";
    constexpr std::string_view SUB = "sub";
    constexpr std::string_view MUL = "mul";
    constexpr std::string_view DIV = "div";

    void start();
    float add(std::vector<float> numbers);
    float sub(std::vector<float> numbers);
    float mul(std::vector<float> numbers);
    float div(std::vector<float> numbers);
}
