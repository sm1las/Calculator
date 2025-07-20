#include "../include/loading.hpp"
#include "../include/matrices.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <limits>

namespace matrices
{

    void start()
    {

        std::cout << std::endl << "===MATRICES===" << std::endl << std::endl;
        std::cout << "Select an operations: " << std::endl;
        std::cout << ADD << " - Matrix addition" << std::endl;
        std::cout << SUB << " - Matrix subtraction" << std::endl;
        std::cout << SMUL << " - Scalar mutliplication" << std::endl;
        std::cout << MMUL << " - Matrix multiplication" << std::endl;
        std::cout << TRANS << " - Matrix transposition" << std::endl;

        std::string choice;
        std::cin >> choice;
        std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

        if (choice == ADD) input(choice);
        else if (choice == SUB) input(choice);
        else if (choice == SMUL) scalar();
        else if (choice == MMUL) input(choice);
        else if (choice == TRANS) transpositional(); 
    }

    void input(std::string choice)
    {

        std::vector<std::vector<float>> matrix1;
        std::vector<std::vector<float>> matrix2;

        size_t rows, cols;
        std::cout << "Enter the ammount of rows and collumns of your matrices: ";
        std::cin >> rows >> cols;
    
        if (std::cin.fail())
        {

            std::cerr << "Numbers only" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return ;
        }

        std::cout << std::endl << "Fill up the first matrix" << std::endl;
        for (size_t i = 0; i < rows; ++i)
        {

            std::vector<float> row;
            for (size_t j = 0; j < cols; ++j)
            {

                float value = 0;
                std::cout << "Enter number for [" << i << "][" << j << "]: ";
                std::cin >> value;
                row.push_back(value);
            }
            matrix1.push_back(row);
        }

        std::cout << std::endl << "Fill up the second matrix" << std::endl;
        for (size_t i = 0; i < rows; ++i)
        {

            std::vector<float> row;
            for (size_t j = 0; j < cols; ++j)
            {

                float value = 0;
                std::cout << "Enter number for [" << i << "][" << j << "]: ";
                std::cin >> value;
                row.push_back(value);
            }
            matrix2.push_back(row);
        }

        if (choice == ADD) add(matrix1, matrix2);
        else if (choice == SUB) sub(matrix1, matrix2);
        else if (choice == MMUL) mmul(matrix1, matrix2);
        else std::cerr << "No such choice" << std::endl;
    }

    void scalar()
    {

        std::vector<std::vector<float>> matrix;
        int scalar;

        size_t rows, cols;
        std::cout << "Enter the ammount of rows and collumns of your matricx: ";
        std::cin >> rows >> cols;

        if (std::cin.fail())
        {

            std::cerr << "Numbers only" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return ;
        }

        std::cout << std::endl << "Fill up your matrix: " << std::endl;

        for (size_t i = 0; i < rows; ++i)
        {

            std::vector<float> row;
            for(size_t j = 0; j < cols; ++j)
            {

                float value = 0;
                std::cout << "Enter number [" << i << "][" << j << "]: ";
                std::cin >> value;
                row.push_back(value);
            }

            matrix.push_back(row);
        }

        std::cout << "Enter your scalar: ";
        std::cin >> scalar;

        if (std::cin.fail())
        {

            std::cerr << "Numbers only" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return ;
        }

        smul(matrix, scalar);
    }

    void transpositional()
    {

        std::vector<std::vector<float>> matrix;
        size_t rows, cols;

        std::cout << "Enter the ammount of rows and collumns of your matrix: ";
        std::cin >> rows >> cols;

        if (std::cin.fail())
        {

            std::cerr << "Numbers only" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return ;
        }

        std::cout << "Fill up your matrix" << std::endl;
        for (size_t i = 0; i < rows; ++i)
        {

            std::vector<float> row;
            for (size_t j = 0; j < cols; ++j)
            {

                float value = 0;
                std::cout << "Enter number [" << i << "][" << j << "]: ";
                std::cin >> value;
                row.push_back(value);
            }

            matrix.push_back(row);
        }

        transpose(matrix);
    }

    std::vector<std::vector<float>> add(
        const std::vector<std::vector<float>>& matrix1,
        const std::vector<std::vector<float>>& matrix2
    )
    {

        size_t rows = matrix1.size();
        size_t cols = matrix1[0].size();

        std::vector<std::vector<float>> result(rows, std::vector<float>(cols));

        loading();
        for (size_t i = 0; i < rows; ++i)
        {

            for (size_t j = 0; j < cols; ++j)
            {

                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        std::cout << "The answer is: " << std::endl;
        for (const auto& row: result)
        {

            for (const auto& val : row)
            {

                std::cout << std::left << std::setw(3) << val;
            }
            std::cout << std::endl;
        }
        return result;
    }

    std::vector<std::vector<float>> sub(
        const std::vector<std::vector<float>>& matrix1,
        const std::vector<std::vector<float>>& matrix2
    )
    {

        size_t rows = matrix1.size();
        size_t cols = matrix1[0].size();

        std::vector<std::vector<float>> result(rows, std::vector<float>(cols));
        loading();

        for (size_t i = 0; i < rows; ++i)
        {

            for (size_t j = 0; j < cols; ++j)
            {

                result[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }

        std::cout << "The answer is: " << std::endl;

        for (const auto& row : result)
        {

            for (const auto& val : row)
            {

                std::cout << std::setw(3) << val;
            }

            std::cout << std::endl;
        }

        return result;
    }

    std::vector<std::vector<float>> mmul(
        const std::vector<std::vector<float>>& matrix1,
        const std::vector<std::vector<float>>& matrix2
    )
    {

        size_t rows = matrix1.size();
        size_t cols = matrix1[0].size();

        std::vector<std::vector<float>> result (rows, std::vector<float>(cols));
        loading();

        if (rows != cols)
        {

            std::cerr << "You can not multiply non-square matrices" << std::endl;
            return {};
        }

        for (size_t i = 0; i < rows; ++i)
        {

            for (size_t j = 0; j < cols; ++j)
            {
            
                float sum = 0;
                for (size_t k = 0; k < rows; ++k)
                {

                    sum += matrix1[i][k] * matrix2[k][j];
                }
                result[i][j] = sum;
            }
        }

        std::cout << "The answer is: " << std::endl;
        for (const auto& row : result)
        {

            for (const auto& val : row)
            {

                std::cout << std::left << std::setw(3) << val;
            }

            std::cout << std::endl;
        }
        return result;
    }

    std::vector<std::vector<float>> transpose(
        const std::vector<std::vector<float>>& matrix
    )
    {

        size_t rows = matrix.size();
        size_t cols = matrix[0].size();

        std::vector<std::vector<float>> result (rows, std::vector<float>(cols));

        loading();

        for (size_t i = 0; i < rows; ++i)
        {

            for (size_t j = 0; j < cols; ++j)
            {

                result[i][j] = matrix[j][i];
            }
        }

        for (const auto& row: result)
        {

            for (const auto& val : row)
            {

                std::cout << std::left << std::setw(3) << val;
            }

            std::cout << std::endl;
        }
        return result;
    }

    std::vector<std::vector<float>> smul(
        const std::vector<std::vector<float>>& matrix,
        float scalar
    )
    {

        size_t rows = matrix.size();
        size_t cols = matrix[0].size();

        std::vector<std::vector<float>> result (rows, std::vector<float>(cols));

        loading();

        for (size_t i = 0; i < rows; ++i)
        {

            for (size_t j = 0; j < cols; ++j)
            {

                result[i][j] = matrix[i][j] * scalar;
            }
        }

        for (const auto& row : result)
        {

            for (const auto& val : row)
            {

                std::cout << std::left << std::setw(3) << val;
            }

            std::cout << std::endl;
        }

        return result;
    }
}
