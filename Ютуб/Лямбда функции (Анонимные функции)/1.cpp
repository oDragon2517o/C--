#include <iostream>
#include <functional>
#include <vector>

using namespace std;

// https://www.youtube.com/watch?v=bP5GJN3-zIo&list=PLQOaTSbfxUtCrKs0nicOg2npJQYSPGO9r&index=183

void Foo(int a)
{
    if (a > 10 && a < 40)
    {
        cout << "FOO" << a << endl;
    }
}

void Bar(int a)
{
    if (a % 2 == 0)
    {
        cout << "BAR" << a << endl;
    }
}

void Baz(int a) {}

void DoWork(vector<int> &vc, function<void(int)> func)
{
    for (auto el : vc)
    {
        func(el);
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    // []() {}; // Общий синтаксис

    [](int a)
    {
        cout << "вызвана анонимная функция с параметром - " << a << endl;
    };

    return 0;
}