#include <iostream>
#include <functional>
#include <vector>

using namespace std;

// https://www.youtube.com/watch?v=bP5GJN3-zIo&list=PLQOaTSbfxUtCrKs0nicOg2npJQYSPGO9r&index=183

class MyClass
{
public:
    int a = 11;
    void Msq()
    {
        cout << "msg" << endl;
    }
    void Lampda()
    {
        auto f = [this]()
        {
            this->Msq();
        };
        f();
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    // []() {}; // Общий синтаксис

    int a = 55;
    {

        auto f = [=]() // захват всез переменныз по значению
        {
            cout << a << endl;
            return 0;
        };

        auto f = [&]() // захват всез переменныз по ссылке
        {
            cout << a << endl;
            return 0;
        };

        auto f = [=]() mutable // захват всез переменныз по значению с редактированием
        {
            cout << a << endl;
            a = 1232;
            cout << a << endl;
            return 0;
        };

        cout << a << endl;
    }

    MyClass m;
    m.Lampda();

    auto g = []() -> float
    {
        return 111;
    };

    auto result = g();

    return 0;
}