#include <iostream>
#include <thread>

using namespace std;

// Отслеживаем жизненный цикл объектов
class Spy
{
public:
    Spy()
    {
        cout << "Spy() in thread " << this_thread::get_id() << "\n";
    }
    Spy(int value)
    {
        cout << "Spy(" << value << ") in thread " << this_thread::get_id() << "\n";
    }
    Spy(const Spy &)
    {
        cout << "Spy(const Spy&) in thread " << this_thread::get_id() << "\n";
    }
    Spy(Spy &&) noexcept
    {
        cout << "Spy(Spy&&) in thread " << this_thread::get_id() << "\n";
    }
    ~Spy()
    {
        cout << "~Spy() in thread " << this_thread::get_id() << "\n";
    }
};

int main()
{
    cout << "Main thread id: " << this_thread::get_id() << "\n";
    thread t1{
        [](Spy)
        {
            cout << "Thread func is invoked in thread "
                 << this_thread::get_id() << "\n";
        },
        Spy()};
    t1.join();
    thread t2{
        [](const Spy &)
        {
            cout << "Thread func is invoked in thread "
                 << this_thread::get_id() << "\n";
        },
        42};
    t2.join();
}