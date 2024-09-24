#include <iostream>

template <typename T>
const T *max(const T *, const T *);
template <typename T>
const T *max(const T[], unsigned);

int main()
{
    int a{4}, b{5};
    std::cout << *max(&a, &b) << std::endl; // 5

    double numbers[]{3.4, 2.3, 6.1, 4.3};
    std::cout << *max(numbers, std::size(numbers)) << std::endl; // 6.1
}
template <typename T>
const T *max(const T *a, const T *b)
{
    return *a > *b ? a : b;
}

template <typename T>
const T *max(const T data[], unsigned size)
{
    const T *result{}; // если вектор пуст, то возвращается nullptr
    for (unsigned i{}; i < size; i++)
    {
        // если result не равен nullptr и *result меньше value
        if (!result || data[i] > *result)
            result = &data[i];
    }
    return result;
}