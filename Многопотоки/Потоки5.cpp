#include <iostream>
#include <thread>
#include <chrono>
// https://www.youtube.com/watch?v=NawpxG81RRk&list=PLQOaTSbfxUtAc_RpyDiWCHq0YTzLtVSD0?

using namespace std;

int Sum(int a, int b)
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "ID потока = " << this_thread::get_id() << "========\t" << "========\t" << "DoWork STARTED\t=======" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "ID потока = " << this_thread::get_id() << "========\t" << "DoWork STOPPED\t=======" << endl;

    return a + b;
}

class MyClass
{

public:
    void DoWork()
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "ID потока = " << this_thread::get_id() << "\t" << "========\t" << "DoWork STARTED\t=======" << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "ID потока = " << this_thread::get_id() << "\t" << "========\t" << "DoWork STOPPED\t=======" << endl;
    };

    void DoWork2(int a)
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "ID потока = " << this_thread::get_id() << "\t" << "========\t" << "DoWork2 STARTED\t=======" << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "ID потока = " << this_thread::get_id() << "\t" << "DpWpork2 значение параметра \t" << a << endl;

        cout << "ID потока = " << this_thread::get_id() << "\t" << "========\t" << "DoWork2 STOPPED\t=======" << endl;
    }

    int Sum(int a, int b)
    {
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "ID потока = " << this_thread::get_id() << "\t" << "========\t" << "Sum STARTED\t=======" << endl;
        this_thread::sleep_for(chrono::milliseconds(3000));
        cout << "ID потока = " << this_thread::get_id() << "\t" << "========\t" << "Sum STOPPED\t=======" << endl;
        return a + b;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");

    int result;
    MyClass m;

    thread t1([&]()
              { result = m.Sum(2, 5); });

    thread t2([&]()
              { m.DoWork(); });

    thread t2a(&MyClass::DoWork, m);

    thread t3(&MyClass::DoWork2, m, 2);

    thread t3a([&]()
               { m.DoWork2(5); });

    for (size_t i = 1; i < +10; i++)
    {
        std::cout << "ID потока = " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    t1.join();
    t2.join();
    t2a.join();
    t3.join();
    t3a.join();

    cout << "Result \t" << result << endl;
    return 0;
}