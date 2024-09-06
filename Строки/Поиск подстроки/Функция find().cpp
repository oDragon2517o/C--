#include <iostream>
#include <string>

int main()
{
    // std::string text{"A friend in need is a friend indeed."};
    // std::cout << text.find("ed") << std::endl;     // 14
    // std::cout << text.find("friend") << std::endl; // 2
    // std::cout << text.find('d') << std::endl;      // 7
    // std::cout << text.find("apple") << std::endl;  // 18446744073709551615

    std::string text{"aaabba aab"};
    std::cout << text.find("a") << std::endl;
    std::cout << text.find("b") << std::endl;
}