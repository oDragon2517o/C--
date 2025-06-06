#include <iostream>
#include <thread>
#include <chrono>
// https://www.youtube.com/watch?v=NawpxG81RRk&list=PLQOaTSbfxUtAc_RpyDiWCHq0YTzLtVSD0?

using namespace std;

void DoWork(int &a)
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "========\t" << "DoWork STARTED\t=======" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    a *= 2;

    cout << "ID потока = "
         << this_thread::get_id()
         << "========\t"
         << "DoWork STOPPED\t======="
         << endl;
    cout << "a=" << a << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");

    int q = 5;

    thread t(DoWork, std::ref(q));

    t.detach();

    for (size_t i = 0; i < 10; i++)
    {
        std::cout << "ID потока = " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    // t.join(); // Для завершения потока DoWork

    cout << q << endl;

    return 0;
}