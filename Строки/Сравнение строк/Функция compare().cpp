#include <iostream>
#include <string>

int main()
{

    // std::string tom{"Tom"};
    // std::string bob{"Bob"};
    // std::string sam{"Sam"};

    // int result = sam.compare(bob);    // 1 - первая строка (sam) больше второй (bob)
    // std::cout << result << std::endl; // 1

    // result = sam.compare(tom);        // -1 - первая строка (sam) меньше второй (tom)
    // std::cout << result << std::endl; // -1

    std::string a("aba");
    std::string b("aaa");
    int result = a.compare(b);
    std::cout << result << std::endl;
}