#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;
// https://www.youtube.com/watch?v=FhlGFJ_zdKM&list=PLQOaTSbfxUtCrKs0nicOg2npJQYSPGO9r&index=140

void Foo(int value)
{
    // throw value;
    if (value < 0)
    {
        // throw value;
        // throw "Число меньше 0 !!!";
        throw runtime_error("Число меньше 0"); // throw exception("Число меньше 0"); не сработает так как автор использует расширение MSVC
    }

    cout << "Переменнас = " << value << endl;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8); // ебаная хуйня скука заебала

    try
    {
        Foo(-50);
    }
    // catch (const int ex)
    // {
    //     cout << "Мы поймали " << ex << endl;
    // }
    // catch (const char *ex)
    // {
    //     cout << "Мы поймали " << ex << endl;
    // }
    catch (const exception &ex)
    {
        cout << "Мы поймали " << ex.what() << endl;
    }

    cin.get();
    return 0;
}
