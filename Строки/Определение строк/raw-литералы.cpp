#include <iostream>
#include <string>

int main()
{
    std::string text{"Name: \t\"Tom\"\nAge:\t38"};
    std::cout << text << std::endl;

    std::string text2{R"(Name:   "Tom" 
    Age:    38)"};
    std::cout << text2 << std::endl;
}