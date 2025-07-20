#include "../include/main_menu.hpp"
#include "../include/single_number.hpp"
#include "../include/mutliple_number.hpp"
#include "../include/quadratic_equation.hpp"
#include "../include/trigonometry.hpp"
#include "../include/matrices.hpp"

#include <limits>
#include <thread>
#include <chrono>
#include <iostream>

void MAIN::start()
{

    std::cout << std::endl << "===CALCULATOR===" << std::endl << std::endl;
    std::cout << "Select operation" << std::endl;
    std::cout << MAIN::EXIT << ". Exit the calculator" << std::endl;
    std::cout << MAIN::SNUM << ". Single number operations" << std::endl;
    std::cout << MAIN::MNUM << ". Multiple numbers operations" << std::endl;
    std::cout << MAIN::QUAE << ". Quadratic equation" << std::endl;
    std::cout << MAIN::TRIG << ". Trigonometric functions" << std::endl;
    std::cout << MAIN::MATR << ". Matrices" << std::endl;

    int choice;
    std::cin >> choice;

    if (std::cin.fail())
    {

        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        std::cerr << "Please enter valid numbers" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return ;
    }

    switch(choice)
    {

        case MAIN::EXIT:
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        std::cout << "Thank you for using my calculator" << std::endl;
        return ;

        case MAIN::SNUM:
        single::start();
        break;

        case MAIN::MNUM:
        multiple::start();
        break;

        case MAIN::QUAE:
        quadratic::start();
        break;

        case MAIN::TRIG:
        trig::start();
        break;

        case MAIN::MATR:
        matrices::start();
        break;

        default:
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        std::cerr << "No such choice" << std::endl;
        return ;
    }
}