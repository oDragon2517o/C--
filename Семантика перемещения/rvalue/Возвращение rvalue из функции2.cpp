#include <iostream>

std::string defaultMessage()
{
    std::string message{"hello world"};
    return message;
}
int main()
{
    std::string text = defaultMessage();
    std::cout << text << std::endl;
}