#include "../include/loading.hpp"
#include <iostream>
#include <chrono>
#include <thread>

void loading()
{

    int steps = 28;
    char spinner = '/';
    while(steps--)
    {

        std::cout << spinner << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << '\b';

        if(spinner == '/') spinner = '-';
        else if(spinner == '-') spinner = '\\';
        else if(spinner == '\\') spinner = '|';
        else if(spinner == '|') spinner = '/';
    }
}