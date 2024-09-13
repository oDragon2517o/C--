#include <iostream>
#include <fstream>

int main()
{
    std::ofstream out;     // поток для записи
    out.open("hello.txt"); // открываем файл для записи
    if (out.is_open())
    {
        out << "Hello World!" << std::endl;
    }
    out.close();
    std::cout << "File has been written" << std::endl;
}