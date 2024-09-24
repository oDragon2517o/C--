#include <iostream>
#include <string>

int main()
{
    std::string people[]{"Tom", "Alice", "Sam", "Bob", "Kate"};
    // сортируем по возрастанию
    bool sorted{};
    do
    {
        sorted = true;    // остается true, если строки отсортированы
        std::string temp; // переменная для обмена значениями
        for (unsigned i{1}; i < std::size(people); i++)
        {
            // если предыдущая строка больше последующей
            if (people[i - 1] > people[i])
            {
                // обмениваем значения
                temp = people[i];
                people[i] = people[i - 1];
                people[i - 1] = temp;
                sorted = false;
            }
        }
    } while (!sorted);
    // вывод строк на консоль
    for (const auto person : people)
    {
        std::cout << person << std::endl;
    }
}