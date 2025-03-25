#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int Sum(int a, int b)
{
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "ID потока = " << this_thread::get_id() << "========\t" << "DoWork STARTED\t=======" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "ID потока = " << this_thread::get_id() << "========\t" << "DoWork STOPPED\t=======" << endl;

    return a + b;
}

/*
class SimpleTimer2
{
public:
    SimpleTimer2()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    ~SimpleTimer2()
    {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;
        std::cout << "Duration: " << duration.count() << "s" << std::endl;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
};
*/
class SimpeTimer
{
public:
    SimpeTimer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~SimpeTimer()
    {
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        cout << "Duration " << duration.count() << "s" << endl;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
};

int main()
{
    SimpeTimer st;
    // auto start = chrono::high_resolution_clock::now();
    setlocale(LC_ALL, "ru");

    int result;

    thread t([&result]()
             { result = Sum(2, 5); });

    // result = Sum(2, 5);

    for (size_t i = 0; i <= 10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tmain works\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    t.join();

    // auto end = chrono::high_resolution_clock::now();

    // chrono::duration<float> duration = end - start;
    // cout << "Duration= " << duration.count() << "s" << endl;

    cout << "Sem Result = " << result << endl;
}