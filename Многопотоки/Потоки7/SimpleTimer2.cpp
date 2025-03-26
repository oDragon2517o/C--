#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class SimpeTimer2
{
public:
    SimpeTimer2()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~SimpeTimer2()
    {
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        cout << "Duration " << duration.count() << "s" << endl;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
};