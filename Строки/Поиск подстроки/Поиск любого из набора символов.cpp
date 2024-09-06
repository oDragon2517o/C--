#include <iostream>
#include <string>

int main()
{
    // std::string text{"Phone number: +23415678901"};
    // std::string letters{"0123456789"};                     // искомые символы
    // std::cout << text.find_first_of(letters) << std::endl; // 15
    // std::cout << text.find_last_of(letters) << std::endl;  // 25

    std::string text{"qwertyeq"};
    std::string letters{"e"};                              // искомые символы
    std::cout << text.find_first_of(letters) << std::endl; // 15
    std::cout << text.find_last_of(letters) << std::endl;  // 25
}