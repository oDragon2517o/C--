#include <iostream>
#include <fstream>
#include <string> // для std::getline

int main()
{
    std::string line;

    std::ifstream in("hello.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    in.close(); // закрываем файл
}