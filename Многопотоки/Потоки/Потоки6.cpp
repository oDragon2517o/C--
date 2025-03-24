#include <iostream>
#include <mutex>
#include <thread>
#include "SimpleTimer.h"

using namespace std;
mutex mtx;
void Print(char ch)
{
    mtx.lock();
    for (int i = 0; i < 5; i++)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << ch;
            this_thread::sleep_for(chrono::milliseconds(20));
        }
        cout << endl;
    }
    cout << endl;
    mtx.unlock();
};

int main()
{
    setlocale(LC_ALL, "ru");

    SimpleTimer timer;
    thread t1(Print, '*');
    thread t2(Print, '#');

    t1.join();
    t2.join();
    return 0;
}