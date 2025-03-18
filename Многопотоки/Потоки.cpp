#include <iostream>
#include <thread>
#include <chrono>
// https://www.youtube.com/watch?v=NawpxG81RRk&list=PLQOaTSbfxUtAc_RpyDiWCHq0YTzLtVSD0?

using namespace std;

void DoWork()
{
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << "ID потока = " << this_thread::get_id() << "\tDoWork\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    thread th(DoWork);

    thread th2(DoWork);

    // th.detach(); // обервет поток

    for (size_t i = 0; i < 10; i++)
    {
        std::cout << "ID потока = " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    th.join(); // дожидаеться завершение потока
    th2.join();
    return 0;
}