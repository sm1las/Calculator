#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>

#include "../include/quadratic_equation.hpp"
#include "../include/loading.hpp"

void quadratic::start()
{

    std::cout << std::endl << "===QUADRATIC EQUATION===" << std::endl << std::endl;
    std::cout << "Enter your choice" << std::endl;
    std::cout << quadratic::D << " - Discriminant" << std::endl;
    std::cout << quadratic::ROOTS << " - Root(s) finder" << std::endl;
    std::cout << quadratic::X0 << " - Find x0" << std::endl;
    std::cout << quadratic::Y0 << " - Find y0" << std::endl;

    std::string choice = "";
    std::cin >> choice;

    std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

    float a, b, c;

    std::cout << std::endl << "Enter numbers to fill the following format:" << std::endl;
    std::cout << "ax^2 + bx + c" << std::endl;

    std::cin >> a >> b >> c;

    if(std::cin.fail())
    {

        std::cerr << "Invalid input" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return ;
    }

    loading();
    formatter(a, b, c);

    if (choice == quadratic::D) discriminant(a, b, c);
    else if(choice == quadratic::ROOTS) roots(a, b, c);
    else if(choice == quadratic::X0) x0(a, b);
    else if(choice == quadratic::Y0) y0(a, b, c);
    else std::cerr << "No such choice" << std::endl;
}

void quadratic::formatter(float a, float b, float c)
{

    //Formatting 'a' part
    if(a == 0)
    {

        std::cerr << "'a' must be more or less than zero" << std::endl;
        return ;
    } else if(a == 1)
    {

        std::cout << "x^2 ";
    } else if(a == -1)
    {

        std::cout << "-x^2 ";
    } else
    {

        std::cout << a << "x^2 ";
    }

    //Formatting 'b' part
    if(b == 1)
    {

        std::cout << "+ x ";
    } else if(b == -1)
    {

        std::cout << "- x ";
    } else if(b > 0)
    {

        std::cout << "+" << b << "x ";
    } else if(b < 0)
    {

        std::cout << b << "x ";
    }

    //Formatting 'c' part
    if(c > 0)
    {

        std::cout << "+ " << c << " = 0" << std::endl;
    } else if(c < 0)
    {

        std::cout << c << " = 0" << std::endl;
    } else
    {

        std::cout << "= 0" << std::endl;
    }
}

float quadratic::discriminant(float a, float b, float c)
{

    loading();
    float D = 0;
    D = pow(b, 2) - 4 * a * c;
    std::cout << "The answer is: " << D << std::endl;
    return 0;
}

float quadratic::roots(float a, float b, float c)
{

    loading();
    float D = 0;
    D = pow(b, 2) - 4 *a * c;

    if(D == 0)
    {

        float x;
        x = (-b - std::sqrt(D)) / (2 * a);

        std::cout << "The answer is: " << x << std::endl;
    } else if(D > 0)
    {

        float x1, x2;
        x1 = (-b - std::sqrt(D)) / (2 * a);
        x2 = (-b + std::sqrt(D)) / (2 * a);

        std::cout << "The answers are: x1 = " << std::min(x1, x2) << "; x2 = " << std::max(x1, x2) << std::endl; 
    } else
    {

        std::cerr << "Parabola doesn't touch OX axis" << std::endl;
        return -1;
    }

    return 0;
}

float quadratic::x0(float a, float b)
{

    loading();
    float x0 = 0;

    x0 = -b / (2 * a);
    std::cout << "The answer is: " << x0 << std::endl;
    return 0;
}

float quadratic::y0(float a, float b, float c)
{
    loading();
    float y0;

    y0 = -(std::pow(b, 2) - 4 * a * c) / (4 * a);
    std::cout << "The answer is: " << y0 << std::endl;
    return 0;
}
