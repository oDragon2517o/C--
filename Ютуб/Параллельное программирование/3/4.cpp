#include <iostream>
#include <thread>
#include <vector>
#include <assert.h>

#include <ranges>
#include <cassert>

using namespace std;

template <typename T>
thread SortVector(vector<T> &values)
{
    return thread{[&values]
                  {
                      ranges::sort(values);
                  }};
};

int main()
{
    vector<int> numbers{10, 2, -5, 3, 17, 5};
    vector<string> string{"one", "two", "three", "foir", "five"};
    {
        auto t1 = SortVector(numbers);
        auto t2 = SortVector(string);
    }
    assert(ranges::is_sorted(numbers));
    assert(ranges::is_sorted(string));
}