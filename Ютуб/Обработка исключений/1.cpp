#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;
// https://www.youtube.com/watch?v=jCW2wRoRi0U

int main()
{

    SetConsoleOutputCP(CP_UTF8); // ебаная хуйня скука заебала

    string path = "myFile2.txt";

    ifstream fin;
    fin.exceptions(ifstream::badbit | ifstream::failbit);

    try
    {
        cout << "Попытка открытия файла" << endl;
        fin.open(path);
        cout << "Файл успешно открыт" << endl;
    }
    // catch (const std::exception &ex)
    // {
    //     cout << ex.what() << endl;
    //     cout << "Ошибка чтения файла" << endl;
    // }

    catch (const ifstream::failure &ex)
    {
        cout << ex.what() << endl;
        cout << ex.code() << endl;

        cout << "Ошибка чтения файла" << endl;
    }
    return 0;
}