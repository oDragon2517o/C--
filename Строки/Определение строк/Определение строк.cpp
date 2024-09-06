#include <iostream>
#include <string>
using namespace std::string_literals;

int main()
{
    std::string message{"Hello METANIT.COM!"};
    std::cout << "Message: " << message << std::endl; // Message: Hello METANIT.COM!

    // std::string message{"hello "s + "world"s + "!"s};
    std::string message2{"hello "s + "world"s + "!"s};
    std::cout << message2 << std::endl; // hello metanit.com
}