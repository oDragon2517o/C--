#include <iostream>

double divide(int a, int b)
{
    if (!b) // если b == 0
    {
        throw "Division by zero";
    }
    return a / b;
}
int main()
{
    try
    {
        try
        {
            int a{10}, b{};
            double result{divide(a, b)};
            std::cout << result << std::endl;
        }
        catch (unsigned error)
        {
            std::cout << "Inner execption: " << error << std::endl;
        }
        std::cout << "Inner try-catch finished" << std::endl; // эта строка не выполняется
    }
    catch (const char *error)
    {
        std::cout << "External execption: " << error << std::endl;
    }
    std::cout << "External try-catch finished" << std::endl;
}