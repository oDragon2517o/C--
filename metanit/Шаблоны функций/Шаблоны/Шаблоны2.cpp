#include <iostream>

template <typename T>
T add(const T &, const T &);

int main()
{
    std::cout << "int: " << add(4, 5) << std::endl;
    std::cout << "double: " << add(4.4, 5.5) << std::endl;
    std::cout << "string: " << add(std::string("hel"), std::string("lo")) << std::endl;
}
template <typename T>
T add(const T &a, const T &b)
{
    return a + b;
}