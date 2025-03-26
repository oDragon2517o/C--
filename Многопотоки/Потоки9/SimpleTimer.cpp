#include "SimpleTimer.h"

SimpleTimer::SimpleTimer()
{
    start = std::chrono::high_resolution_clock::now();
}
SimpleTimer::~SimpleTimer()
{
    end = std::chrono::high_resolution_clock::now();
    // auto duration = end - start;
    // float result = duration.count();

    std::chrono::duration<double> duration = end - start;

    std::cout << "Прошло времени" << duration.count() << " секунд" << std::endl;
}