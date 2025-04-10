#include <iostream>
#include <locale>
#include <chrono>
#include <thread>
#include <windows.h>

//  https : // www.youtube.com/watch?v=kXng09pmfwM&t=2s
using namespace std;

class A
{
public:
    A()
    {
        cout << "Вызов коструктора класса A" << endl;
    }
    ~A()
    {
        cout << "Вызов деструктора класса A" << endl;
    }
};

class B : public A
{

public:
    B()
    {
        cout << "Вызов коструктора класса B" << endl;
    }
    ~B()
    {
        cout << "Вызов деструктора класса B" << endl;
    }
};

class C : public B

{

public:
    C()
    {
        cout << "Вызов коструктора класса C" << endl;
    }
    ~C()
    {
        cout << "Вызов деструктора класса C" << endl;
    }
};

class MyClass
{
    int *data;

public:
    MyClass(int size)
    {
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = i;
        }

        cout << "Объект " << data << " Вызвал конструктор" << endl;
    }

    ~MyClass()
    {

        delete[] data;
        cout << "Объект " << data << " Вызвал деструктор" << endl;
    }
};
void Foo()
{

    cout << "Foo начал свое выполнение" << endl;
    MyClass a(1);
    cout << "Foo конец свое выполнение" << endl;
}
int main()
{
    // setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(CP_UTF8); // Устанавливаем UTF-8 для консоли

    Foo();
    // B value;
    // cout << endl
    //      << endl;

    return 0;
}