#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;
// https://www.youtube.com/watch?v=wCUl7yTHWq8&list=PLQOaTSbfxUtCrKs0nicOg2npJQYSPGO9r&index=142

class MyException : public exception
{

public:
    // MyException(const char *msg) : message(msg)
    // {
    // }
    // const char *what() const noexcept override
    // {
    //     return message;
    // }

    MyException(const char *msg, int dataState) : message(msg)
    {
        this->dataState = dataState;
    }
    int GetDataState() const
    {
        return dataState;
    }

    const char *what() const noexcept override
    {
        return message;
    }

private:
    const char *message;
    int dataState;
};

void Foo(int value)
{
    // throw value;
    if (value < 0)
    {
        // throw value;
        // throw "Число меньше 0 !!!";
        throw runtime_error("Число меньше 0");
    }

    if (value == 1)
    {
        throw MyException("Число = 1 !!!", value);
    }

    cout << "Переменнас = " << value << endl;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8); // ебаная хуйня скука заебала

    try
    {
        Foo(1);
    }
    // catch (const int ex)
    // {
    //     cout << "Мы поймали " << ex << endl;
    // }

    catch (const MyException &ex)
    {
        cout << "Блок 1 Мы поймали " << ex.what() << endl;
        cout << "Состояние данных " << ex.GetDataState() << endl;
    }
    catch (const char *ex)
    {
        cout << "Блок 2 Мы поймали " << ex << endl;
    }
    // catch (...) // Ловит все исключения
    // {
    //     cout << "Что то пошло не так" << endl;
    // }

    cin.get();
    return 0;
}
