#include <iostream>
#include <cctype>
#include <limits>
#include <algorithm>

#include "../include/mutliple_number.hpp"
#include "../include/loading.hpp"

void multiple::start()
{

    std::cout << std::endl << "===MULTIPLE NUMBERS===" << std::endl << std::endl;
    std::cout << "Enter your choice: " << std::endl;
    std::cout << multiple::ADD << " - Add" << std::endl;
    std::cout << multiple::SUB << " - Subtract" << std::endl;
    std::cout << multiple::MUL << " - Multiply" << std::endl;
    std::cout << multiple::DIV << " - Division" << std::endl;

    std::string choice = "";
    std::cin >> choice;

    std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

    int n;
    std::vector<float> numbers;
    std::cout << "Enter how many numbers you will be using: ";
    std::cin >> n;

    for(int i = 0; i < n; ++i)
    {

        float value = 0;
        std::cout << "Enter number No." << i + 1 << ": ";
        std::cin >> value;

            if(std::cin.fail())
            {

                std::cerr << "Numbers only" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return ;
            }

        numbers.push_back(value);
    }

    if(choice == multiple::ADD) add(numbers);
    else if(choice == multiple::SUB) sub(numbers);
    else if(choice == multiple::MUL) mul(numbers);
    else if(choice == multiple::DIV) div(numbers);
    else std::cerr << "No such choice" << std::endl;
}

float multiple::add(std::vector<float> nums)
{
    float answer = 0;
    loading();
    for(int i = 0; i < nums.size(); ++i)
    {

        answer += nums[i];
    }

    std::cout << "The answer is: " << answer << std::endl;
    return 0;
}

float multiple::sub(std::vector<float> nums)
{

    float answer = nums[0];
    loading();

    for (int i = 1; i < nums.size(); ++i)
    {

        answer -= nums[i];
    }

    std::cout << "The answer is: " << answer << std::endl;
    return 0;
}

float multiple::mul(std::vector<float> nums)
{

    float answer = 1;
    loading();

    for (int i = 0; i < nums.size(); ++i)
    {

        answer *= nums[i];
    }

    std::cout << "The answer is: " << answer << std::endl;
    return 0;
}

float multiple::div(std::vector<float> nums)
{

    float answer = nums[0];
    loading();

    for (int i = 1; i < nums.size(); ++i)
    {

        if (nums[i] == 0)
        {

            std::cerr << "You can't divide by zero" << std::endl;
            return -1;
        }

        answer /= nums[i];
    }

    std::cout << "The answer is: " << answer << std::endl;
    return 0;
}
