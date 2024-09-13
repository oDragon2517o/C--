#include <iostream>

class Sum
{
public:
    int operator()(int x, int y) const { return x + y; }
};

int main()
{
    Sum sum;                               // определяем объект функции
    int result{sum(2, 3)};                 // вызываем объект функции
    std::cout << result << std::endl;      // 5
    std::cout << sum(5, 3) << std::endl;   // 8
    std::cout << sum(12, 13) << std::endl; // 25
}