#include "../include/trigonometry.hpp"
#include "../include/loading.hpp"

#include <cmath>
#include <iostream>
#include <numbers>
#include <algorithm>
#include <limits>
#include <cctype>

using std::numbers::pi;

void trig::start()
{

    std::cout << std::endl << "===TRIGONOMETRY===" << std::endl << std::endl;
    std::cout << "Select function: " << std::endl;
    std::cout << trig::sine << " - sin(x)" << std::endl;
    std::cout << trig::cosine << " - cos(x)" << std::endl;
    std::cout << trig::tangent << " - tan(x)" << std::endl;
    std::cout << trig::cosecant << " - csc(x)" << std::endl;
    std::cout << trig::secant << " - sec(x)" << std::endl;
    std::cout << trig::cotangent << " - cot(x)" << std::endl;
    std::cout << trig::arcsine << " - asin(x)" << std::endl;
    std::cout << trig::arccosine << " - acos(x)" << std::endl;
    std::cout << trig::arctangent << " - atan(x)" << std::endl;

    std::string choice = "";
    std::cin >> choice;

    std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

    float a;

    std::cout << "Enter a number: ";
    std::cin >> a;

    if (std::cin.fail())
    {

        std::cerr << "Invalid input" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return ;
    }

    if (choice == trig::sine) SIN(a);
    else if(choice == trig::cosine) COS(a);
    else if(choice == trig::tangent) TAN(a);
    else if(choice == trig::cosecant) CSC(a);
    else if(choice == trig::secant) SEC(a);
    else if(choice == trig::cotangent) COT(a);
    else if(choice == trig::arcsine) ASIN(a);
    else if(choice == trig::arccosine) ACOS(a);
    else if(choice == trig::arctangent) ATAN(a);
    else std::cerr << "No such choice" << std::endl;
}

bool trig::isCloseToZero(float a, float tolerance = 1e-6f)
{

    return std::fabs(a) < tolerance;
}

float answer;
char choice;

float trig::SIN(float a)
{

    loading();
    answer = std::sin(a);

    std::cout << "Do you want your answer in degrees [y/n]: ";
    std::cin >> choice;
    choice = std::tolower(static_cast<unsigned char>(choice));

    if (choice == 'y')
    {

        loading();
        answer = std::sin(a * (pi / 180.f));

        std::cout << "The answer is: " << answer << std::endl;
        return 0;
    } else if(choice == 'n')
    {

        std::cout << "The answer is: " << answer << std::endl;
    } else 
    {

        std::cout << "No such choice" << std::endl;
    }

    return 0;
}

float trig::COS(float a)
{
    loading();
    answer = std::cos(a);

    std::cout << "Do you want your answer in degrees [y/n]: ";
    std::cin >> choice;
    choice = std::tolower(static_cast<unsigned char>(choice));

    if(choice == 'y')
    {

        loading();
        answer = std::cos(a * (pi / 180.f));

        std::cout << "The answer is: " << answer << std::endl;
    }else if(choice == 'n')
    {

        std::cout << "The answer is: " << answer << std::endl;
    } else
    {

        std::cout << "No such choice" << std::endl;
    }
    return 0;
}

float trig::TAN(float a)
{
    
    loading();
    if(isCloseToZero(std::tan(a)))
    {

        std::cerr << "Too close to zero. Unable to divide" << std::endl;
        return -1;
    }else
    {

        answer = std::tan(a);

        std::cout << "Do you want your answer in degrees [y/n]: ";
        std::cin >> choice;
        choice = std::tolower(static_cast<unsigned char>(choice));

        if(choice == 'y')
        {

            loading();
            answer = std::tan(a * (pi / 180.f));
            std::cout << "The answer is: " << answer << std::endl;
        } else if(choice == 'n')
        {

            std::cout << "The answer is: " << answer << std::endl;
        } else
        {

            std::cerr << "No such choice" << std::endl;
        }
    }
    return 0;
}

float trig::CSC(float a)
{

    loading();
    float sin_a = std::sin(a );

    if(isCloseToZero(sin_a))
    {

        std::cerr << "sin(a) is too close to zero" << std::endl;
        return -1;
    } else
    {

        answer = 1.f / sin_a;
        std::cout << "Do you want your answer is degrees[y/n]: ";
        std::cin >> choice;
        choice = std::tolower(static_cast<unsigned char>(choice));

        if(choice == 'y')
        {

            loading();
            answer = 1.f / sin(a * (pi / 180.f));
            std::cout << "The answer is: " << answer << std::endl;
        } else if(choice == 'n')
        {

            std::cout << "The answer is: " << answer << std::endl;
        } else
        {

            std::cerr << "No such choice" << std::endl;
        }
    }
    return 0;
}

float trig::SEC(float a)
{

    loading();
    float cos_a = std::cos(a);

    if(isCloseToZero(cos_a))
    {

        std::cerr << "cos(a) is too close to zero" << std::endl;
        return -1;
    } else
    {

        answer = 1.f / cos_a;
        std::cout << "Do you want your answer in degrees[y/n]: ";
        std::cin >> choice;
        choice = std::tolower(static_cast<unsigned char>(choice));

        if (choice == 'y')
        {

            loading();
            answer = 1.f / cos(a * (pi / 180.f));
            std::cout << "The answer is: " << answer << std::endl;
        } else if(choice == 'n')
        {

            std::cout << "The answer is: " << answer << std::endl;
        } else
        {

            std::cerr << "No such choice" << std::endl;
        }
    }
    return 0;
}

float trig::COT(float a)
{

    loading();
    float tan_a = std::tan(a);

    if(isCloseToZero(tan_a))
    {

        std::cerr << "tan(a) is too close to zero" << std::endl;
        return -1;
    }else 
    {

        answer = 1.f / tan_a;
        std::cout << "Do you want your answer in degrees[y/n]: ";
        std::cin >> choice;
        choice = std::tolower(static_cast<unsigned char>(choice));

        if(choice == 'y')
        {

            loading();
            answer = 1.f / std::tan(a * (pi / 180.f));
            std::cout << "The answer is: " << answer << std::endl;
        } else if(choice == 'n')
        {

            std::cout << "The answer is: " << answer << std::endl;
        } else
        {

            std::cerr << "No such choice" << std::endl;
        }
    }
    return 0;
}

float trig::ASIN(float a)
{

    loading();
    answer = std::asin(a);

    std::cout << "Do you want your answer in degrees[y/n]: ";
    std::cin >> choice;
    choice = std::tolower(static_cast<unsigned char>(choice));

    if(choice == 'y')
    {

        loading();
        answer = std::asin(a * (pi / 180.f));
        std::cout << "The answer is: " << answer << std::endl;
    } else if(choice == 'n')
    {

        std::cout << "The answer is: " << answer << std::endl;
    } else
    {

        std::cerr << "No such choice" << std::endl;
    }
    return 0;
}

float trig::ACOS(float a)
{

    loading();
    answer = std::acos(a);

    std::cout << "Do you want your answer in degrees[y/n]: ";
    std::cin >> choice;
    choice = std::tolower(static_cast<unsigned char>(choice));

    if(choice == 'y')
    {

        loading();
        answer = std::acos(a * (pi / 180.f));
        std::cout << "The answer is: " << answer << std::endl;
    } else if(choice == 'n')
    {

        std::cout << "The answer is: " << answer << std::endl;
    }else
    {

        std::cerr << "No such choice" << std::endl;
    }
    return 0;
}

float trig::ATAN(float a)
{

    loading();
    answer = std::atan(a);

    std::cout << "Do you want your answer in degrees[y/n]: ";
    std::cin >> choice;
    choice = std::tolower(static_cast<unsigned char>(choice));

    if(choice == 'y')
    {

        loading();
        answer = std::atan(a * (pi / 180.f));
        std::cout << "The answer is: " << answer << std::endl;
    } else if(choice == 'n')
    {

        std::cout << "The answer is: " << answer << std::endl;
    } else
    {

        std::cerr << "No such choice" << std::endl;
    }
    return 0;
}
