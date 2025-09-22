#include <iostream>
#include <thread>

using namespace std;

void SayHello()
{
    cout << "Hello, world \n";
}

class BgTask
{
public:
    explicit BgTask(string name) : m_name(move(name)) {}

    void operator()()
    {
        cout << "Hello from bg task" << m_name << endl;
    }

private:
    string m_name;
};

void TestCopyableTsk()
{
    BgTask BgTask{"Task 1"}; // Объект BgTask будет скопирован внутрь потока
    thread t{BgTask};
}

class MoveOnlyTask
{
public:
    explicit MoveOnlyTask(unique_ptr<int> data) : m_data(move(data)) {}
    void operator()()
    {
        cout << "Hellp from MoveOnlyTask with data: " << *m_data << endl;
    }

private:
    unique_ptr<int> m_data;
};

class Func
{
    int &m_dataFef;

public:
    Func(int &data) : m_dataFef(data) {}
    void operator()()
    {
        for (int i = 0; i < 100000; ++i)
        {
            cout << m_dataFef << endl;
        }
    }
};

int main()
{
    thread t{SayHello}; // Создание потока
    t.join();           // Ждем завершение работы потока

    thread t{SayHello}; // Создание потока
    t.detach();         // Отцепляем поток от  объекта thread

    /////////////////////////////////////////////////

    cout << "This there id:" << this_thread::get_id() << "\n";

    thread bgThread{
        []
        { cout << "In bg thread. ID is" << this_thread::get_id() << "\n"; }};

    cout << "Bg thread id:" << bgThread.get_id() << "\n";
    bgThread.join();
    cout << "After join bg thread id:" << bgThread.get_id() << "\n";

    /////////////////////////

    int data = 42;
    thread(Func{data}).detach();
}