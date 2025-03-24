#include "SimpleTimer.h"

SimpleTimer::SimpleTimer()
{
    start = std::chrono::high_resolution_clock::now();
}
SimpleTimer::~SimpleTimer()
{
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    // duration = std::chrono::duration_cast<std::chrono::duration<float>>(end - start);
    float result = duration.count();
    std::cout << "Прошло времени" << result << " секунд" << std::endl;
}