#include <iostream>
#include <string>

int main()
{
    std::string text{"hello world!"};
    std::string hello{"hello"};

    // проверка, начинаяется ли text на строку hello
    if (text.starts_with(hello))
    {
        std::cout << "The text starts with " << hello << std::endl;
    }
}