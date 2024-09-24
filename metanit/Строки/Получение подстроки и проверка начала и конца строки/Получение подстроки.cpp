#include <iostream>
#include <string>

int main()
{
    std::string message{"tom@localhost.com"};
    std::string submessage = message.substr(10, 9); // 9 символов начиная с 4-го
    std::cout << submessage << std::endl;           // localhost
}