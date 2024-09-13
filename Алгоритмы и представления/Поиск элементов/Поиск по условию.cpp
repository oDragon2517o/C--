#include <iostream>
#include <vector>
#include <algorithm>

// если число четное
bool is_even(int n) { return n % 2 == 0; }
// если число положительное
bool is_positive(int n) { return n > 0; }
// если число больше 10
bool is_greater10(int n) { return n > 10; }

template <typename T>
void findValue(const std::vector<T> &data, bool (*condition)(T))
{
    auto result{std::find_if(begin(data), end(data), condition)};
    if (result == end(data))
        std::cout << "Value not found" << std::endl;
    else
        std::cout << "Value found at position " << (result - begin(data)) << std::endl;
}

int main()
{
    std::vector<int> numbers{-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    findValue(numbers, is_even);      // Value found at position 1
    findValue(numbers, is_positive);  // Value found at position 6
    findValue(numbers, is_greater10); // Value not found
}