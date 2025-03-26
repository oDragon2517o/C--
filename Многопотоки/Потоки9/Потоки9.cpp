#include <iostream>
#include <mutex>
#include <thread>
#include "SimpleTimer.h"
// using namespace SimpleTimer2;

using namespace std;

recursive_mutex rm;

void Foo(int a)
{
    rm.lock();
    cout << a << " ";
    this_thread::sleep_for(chrono::milliseconds(300));
    if (a <= 1)
    {
        cout << endl;
        rm.unlock();
        return;
    }
    a--;
    Foo(a);
    rm.unlock();
}

int main()
{
    setlocale(LC_ALL, "ru");

    // Foo(10);
    thread t1(Foo, 10);
    thread t2(Foo, 10);

    t1.join();
    t2.join();

    return 0;
}