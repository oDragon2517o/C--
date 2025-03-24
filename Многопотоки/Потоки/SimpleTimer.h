#pragma onece

#include <chrono>
#include <iostream>

class SimpleTimer
{
public:
    SimpleTimer();

    ~SimpleTimer();

private:
    // std::chrono::time_point<std::chrono::steady_clock> start;
    // std::chrono::time_point<std::chrono::steady_clock> end;

    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;

    std::chrono::duration<float> duration;
};

/*
#ifndef SIMPLE_TIMER_H
#define SIMPLE_TIMER_H

#include <chrono>
#include <iostream>

class SimpleTimer
{
private:
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    std::chrono::duration<float> duration;

public:
    SimpleTimer();
    ~SimpleTimer();
};

#endif

*/