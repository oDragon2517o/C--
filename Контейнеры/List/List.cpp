#include <list>

int main()
{
    std::list<int> list1;                // пустой список
    std::list<int> list2(5);             // список list2 состоит из 5 чисел, каждый элемент имеет значение по умолчанию
    std::list<int> list3(5, 2);          // список list3 состоит из 5 чисел, каждое число равно 2
    std::list<int> list4{1, 2, 4, 5};    // список list4 состоит из чисел 1, 2, 4, 5
    std::list<int> list5 = {1, 2, 3, 5}; // список list5 состоит из чисел 1, 2, 4, 5
    std::list<int> list6(list4);         // список list6 - копия списка list4
    std::list<int> list7 = list4;        // список list7 - копия списка list4
}