#include <iostream>
#include <thread>
#include <chrono>
// https://www.youtube.com/watch?v=NawpxG81RRk&list=PLQOaTSbfxUtAc_RpyDiWCHq0YTzLtVSD0?

using namespace std;

int Sum(int a, int b)
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "========\t" << "DoWork STARTED\t=======" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "ID потока = " << this_thread::get_id() << "========\t" << "DoWork STOPPED\t=======" << endl;

    return a + b;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int result;

    thread t([&result]()
             { result = Sum(2, 5); });

    // cout << "Sum result =" << result << endl;

    for (size_t i = 0; i < 10; i++)
    {
        std::cout << "ID потока = " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    t.join();
    cout << "Sum Result = " << result << endl;

    return 0;
}