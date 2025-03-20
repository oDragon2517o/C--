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

void Baz(int a)
{
    cout << "BAR" << a << endl;
}

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

     vector<int>
        vc = {1, 51, 4, 10, 44, 98, 8, 12, 22, 29, 49};

    int p = 0;

    [&p](int a)
    {
        p = 5;
    };

    // Стандарт 14
    auto f = [&p]()
    {
        p = 5;
    };
    f();

    DoWork(vc, [](int a)
           { cout << "вызвана анонимная функция с параметром - " << a << endl; });

    DoWork(vc, [](int a)
           {     
            if (a % 2 == 0)
            {
                cout << "Лямбда " << a << endl;
            } });

    return 0;
}