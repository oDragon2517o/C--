#include <iostream>
#include <mutex>
#include <thread>
#include "SimpleTimer.h"
// using namespace SimpleTimer2;

using namespace std;
mutex mtx;
mutex mtx2;
void Print(char ch)
{
    // mtx.lock();

    this_thread::sleep_for(chrono::milliseconds(2000));
    {
        lock_guard<mutex> guard(mtx);

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
    } // {} ограничили обрать видимости для lock_guard<mutex> guard(mtx);

    this_thread::sleep_for(chrono::milliseconds(2000));
    // mtx.unlock();
};

void Print2(char ch)
{
    // mtx.lock();

    this_thread::sleep_for(chrono::milliseconds(2000));
    {
        lock_guard<mutex> guard(mtx2);

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
    } // {} ограничили обрать видимости для lock_guard<mutex> guard(mtx);

    this_thread::sleep_for(chrono::milliseconds(2000));
    // mtx.unlock();
};

int main()
{
    setlocale(LC_ALL, "ru");

    SimpleTimer timer;
    thread t1(Print, '*');
    thread t12(Print2, '+');
    thread t2(Print, '#');
    thread t3(Print, '$');

    t1.join();
    t2.join();
    t12.join();
    t3.join();
    return 0;
}