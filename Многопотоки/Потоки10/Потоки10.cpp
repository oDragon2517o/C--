#include <iostream>
#include <mutex>
#include <thread>
#include "SimpleTimer.h"
// using namespace SimpleTimer2;

using namespace std;

mutex mtx;

void Print(char ch)
{

    // lock_guard<mutex> lg(mtx);
    unique_lock<mutex> ul(mtx, std::defer_lock);

    this_thread::sleep_for(chrono::milliseconds(2000));
    ul.lock();
    for (int i = 0; i < 5; i++)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << ch;
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        cout << endl;
    }
    cout << endl;
    ul.unlock();

    this_thread::sleep_for(chrono::milliseconds(2000));
};

int main()
{
    setlocale(LC_ALL, "ru");
    SimpleTimer timer;
    thread t1(Print, '@');
    thread t2(Print, '#');

    t1.join();
    t2.join();

    return 0;
}