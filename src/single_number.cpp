#include "../include/single_number.hpp"
#include "../include/loading.hpp"

#include <iostream>
#include <cctype>
#include <thread>
#include <chrono>
#include <cmath>
#include <limits>
#include <algorithm>

void single::start()
{

    std::cout << std::endl << "===SINGLE NUMBER===" << std::endl << std::endl;
    std::cout << single::SROOT << " - Square root" << std::endl;
    std::cout << single::CROOT << " - Cubic root" << std::endl;
    std::cout << single::SQUARE << " - Square" << std::endl;
    std::cout << single::CUBE << " - Cube" << std::endl;
    std::cout << single::FACTORIAL << " - Factorial" << std::endl;

    std::string choice = "";
    std::cin >> choice;

    std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

    std::cout << std::endl << "Enter the number: ";

    float number = 0.f;
    std::cin >> number;

    if(std::cin.fail())
    {

        std::cerr << "Numbers only" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return ;
    }

    if(choice == single::SROOT) sroot(number);
    else if(choice == single::CROOT) croot(number);
    else if(choice == single::SQUARE) square(number);
    else if(choice == single::CUBE) cube(number);
    else if(choice  == single::FACTORIAL) factorial(number);
    else std::cerr << "No such choice" << std::endl;
}

bool single::isInteger(float number)
{

    return std::floor(number) == number;
}

float single::sroot(float number)
{

    loading();
    if(number < 0)
    {

        std::cerr << "Invalid input" << std::endl;
        return -1;
    }
    
    std::cout << "The answer is: " << std::sqrt(number) << std::endl;
    return 0;
}

float single::croot(float number)
{
    loading();

    std::cout << "The answer is: " << std::cbrt(number) << std::endl;
    return 0;
}

float single::square(float number)
{

    loading();

    std::cout << "The answer is: " << std::pow(number, 2) << std::endl;
    return 0;
}

float single::cube(float number)
{

    loading();

    std::cout << "The answer is: " << std::pow(number, 3) << std::endl;
    return 0;
}

long single::factorial(float number)
{

    loading();
    unsigned long long answer = 1;
    if(number < 0)
    {

        std::cerr << "Invalid input" << std::endl;
        return -1;
    } else if(!isInteger(number))
    {

        std::cerr << "Invalid input" << std::endl;
        return -1;
    } else
    {

        int n = static_cast<int>(number);
        for(int i = 2; i <= n; ++i)
        {

            answer *= i;
        }

        std::cout << "The answer is: " << answer << std::endl;
    }
    return 0;
}
