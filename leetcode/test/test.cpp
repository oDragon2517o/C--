#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    std::unordered_map<char, int> charIndex;
    std::string str = "hello";

    for (char ch : str)
    {
        charIndex[ch]++;
    }

    for (const auto &pair : charIndex)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}