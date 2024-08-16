#include <iostream>

void print(const std::string &);

const std::string message{"hello"};
int main()
{
    ::print(::message);
}

void print(const std::string &text)
{
    std::cout << text << std::endl;
}
