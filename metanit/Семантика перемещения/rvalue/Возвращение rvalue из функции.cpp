#include <iostream>

void print(std::string &&text)
{
    std::cout << text << std::endl;
}

std::string defaultMessage()
{
    std::string message{"hello world"};
    return message;
}
int main()
{
    print(defaultMessage()); // передаем rvalue
}