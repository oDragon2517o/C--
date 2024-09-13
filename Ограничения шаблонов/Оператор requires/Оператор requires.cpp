#include <iostream>

template <typename T>
    requires std::is_same<T, int>::value || std::is_same<T, double>::value
T sum(T a, T b)
{
    return a + b;
}

int main()
{
    std::cout << sum(3, 4) << std::endl;
    std::cout << sum(12.5, 4.3) << std::endl;
    // std::cout << sum(5l, 7l) << std::endl;
}