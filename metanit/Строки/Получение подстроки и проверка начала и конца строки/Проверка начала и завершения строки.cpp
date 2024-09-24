#include <iostream>
#include <string>

int main()
{
    std::string text{"1hello world!"};
    std::string hello{"hello"};

    // проверка, начинаяется ли text на строку hello
    // с помощью функции compare
    if (text.compare(0, hello.length(), hello) == 0)
    {
        std::cout << "The text starts with " << hello << std::endl;
    }
    // с помощью функции substr
    if (text.substr(0, hello.length()) == hello)
    {
        std::cout << "The text starts with " << hello << std::endl;
    }
}