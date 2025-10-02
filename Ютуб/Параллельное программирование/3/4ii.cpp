#include <iostream>
#include <thread>
#include <vector>
#include <cassert>
#include <algorithm> // Для std::sort и std::is_sorted

using namespace std;

// Исправляем синтаксис функции SortVector
template <typename T>
std::thread SortVector(vector<T> &values)
{
    return std::thread{[&values]
                       {
                           std::sort(values.begin(), values.end());
                       }};
}

int main()
{
    vector<int> numbers{10, 2, -5, 3, 17, 5};
    vector<string> strings{"one", "two", "three", "four", "five"}; // Исправлено "foir" на "four"

    {
        auto t1 = SortVector(numbers);
        auto t2 = SortVector(strings);

        // Ждем завершения потоков
        t1.join();
        t2.join();
    }

    // Проверяем, отсортированы ли векторы
    assert(std::is_sorted(numbers.begin(), numbers.end()));
    assert(std::is_sorted(strings.begin(), strings.end()));

    // Для проверки результата (опционально)
    for (const auto &num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;
    for (const auto &str : strings)
    {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}