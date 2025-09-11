#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;
// youtube.com/watch?v=guLK7Up6Kmc&list=PLQOaTSbfxUtCrKs0nicOg2npJQYSPGO9r&index=141

void Foo(int value)
{
    // throw value;
    if (value < 0)
    {
        // throw value;
        throw "Число меньше 0 !!!";
        // throw runtime_error("Число меньше 0");
    }

    if (value == 0)
    {
        throw runtime_error("Число Равно 0!!!");
    }

    if (value == 1)
    {
        throw 1;
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

    catch (const exception &ex)
    {
        cout << "Блок 1 Мы поймали " << ex.what() << endl;
    }
    catch (const char *ex)
    {
        cout << "Блок 2 Мы поймали " << ex << endl;
    }
    catch (...) // Ловит все исключения
    {
        cout << "Что то пошло не так" << endl;
    }

    cin.get();
    return 0;
}
