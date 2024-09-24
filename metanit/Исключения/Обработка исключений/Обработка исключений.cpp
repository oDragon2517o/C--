#include <iostream>

double divide(int a, int b)
{
    if (b)
        return a / b;
    throw std::string{"Division by zero!!"};
}

int main()
{
    int x{500};
    int y{};

    try
    {
        double z{divide(x, y)};
        std::cout << z << std::endl;
    }
    catch (const std::string &error_message)
    {
        std::cout << error_message << std::endl;
    }
    std::cout << "The End..." << std::endl;
}
