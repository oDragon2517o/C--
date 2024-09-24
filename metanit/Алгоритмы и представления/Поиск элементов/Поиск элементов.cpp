#include <iostream>
#include <vector>
#include <algorithm>

void findValue(const std::vector<int> &data, int value)
{
    auto result{std::find(begin(data), end(data), value)};
    if (result == end(data))
        std::cout << "Value not found" << std::endl;
    else
        std::cout << "Value found at position " << (result - begin(data)) << std::endl;
}

int main()
{
    std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8};
    findValue(numbers, 4);  // Value found at position 3
    findValue(numbers, 12); // Value not found
}