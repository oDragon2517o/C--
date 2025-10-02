#include <iostream>
#include <thread>
#include <vector>
#include <assert.h>

#include <ranges>
#include <cassert>
#include <algorithm>

using namespace std;

template <typename T>
std::thread SortVector(vector<T> &values)
{
    return thread{
        [&values]
        {
            std::sort(values.begin(), values.end());
        }};
};

int main()
{
    vector<int> numbers{10, 2, -5, 3, 17, 5};
    vector<string> strings{"one", "two", "three", "foir", "five"};
    {
        auto t1 = SortVector(numbers);
        auto t2 = SortVector(strings);
    }

    // assert(std::ranges::is_sorted(numbers);
    // assert(std::ranges::is_sorted(string));

    assert(std::is_sorted(numbers.begin(), numbers.end()));
    assert(std::is_sorted(strings.begin(), strings.end()));
}