#include <iostream>
#include <string>
#include <cstdlib> // Для функции strtol

int main()
{
    std::string str = "1234";                    // Пример строки
    int *numbers = nullptr;                      // Указатель на массив чисел
    int size = strtol(str.c_str(), nullptr, 10); // Преобразование строки в целое число

    if (size == 0 && errno == ERANGE)
    {
        std::cout << "Преобразование не удалось из-за слишком большого числа." << std::endl;
    }
    else
    {
        numbers = new int[size]; // Выделение памяти для массива чисел

        for (int i = 0; i < size; ++i)
        {
            numbers[i] = strtol(str.c_str() + i * sizeof(char), nullptr, 10);
        }

        // Теперь вы можете работать с массивом чисел
        for (int num : numbers)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        delete[] numbers; // Освобождение памяти после использования
    }

    return 0;
}