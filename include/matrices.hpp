#pragma once

#include <vector>
#include <string_view>
#include <string>

namespace matrices
{

    constexpr std::string_view ADD = "add";
    constexpr std::string_view SUB = "sub";
    constexpr std::string_view SMUL = "smul"; //Scalar multiplication
    constexpr std::string_view MMUL = "mmul"; //Matrix multiplication
    constexpr std::string_view TRANS = "trans"; //Transposition

    void start();
    std::vector<std::vector<float>> add(
        const std::vector<std::vector<float>>& matrix1,
        const std::vector<std::vector<float>>& matrix2
    );

    std::vector<std::vector<float>> sub(
        const std::vector<std::vector<float>>& matrix1,
        const std::vector<std::vector<float>>& matrix2
    );

    std::vector<std::vector<float>> smul(
        const std::vector<std::vector<float>>& matrix,
        float scalar
    );

    std::vector<std::vector<float>> mmul(
        const std::vector<std::vector<float>>& matrix1,
        const std::vector<std::vector<float>>& matrix2
    );

    std::vector<std::vector<float>> transpose(
        const std::vector<std::vector<float>>& matrix
    );

    void input(std::string choice); //Used for those functions that require two matrices
    void scalar(); //scalar multiplication input
    void transpositional(); //also self-explanatory
}