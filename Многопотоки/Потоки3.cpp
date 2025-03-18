#include <iostream>
#include <thread>
#include <chrono>
// https://www.youtube.com/watch?v=NawpxG81RRk&list=PLQOaTSbfxUtAc_RpyDiWCHq0YTzLtVSD0?

using namespace std;

void Sum(int a, int b)
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "========\t" << "DoWork STARTED\t=======" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "a+b = " << a + b << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "========\t" << "DoWork STOPPED\t=======" << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");

    thread th(Sum, 2, 3);

    for (size_t i = 0; true; i++)
    {
        std::cout << "ID потока = " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    th.join();

    return 0;
}