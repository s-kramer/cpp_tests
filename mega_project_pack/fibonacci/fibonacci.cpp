#include "fibonacci.h"
#include <algorithm>

int getNthFibonacci(int step, bool recalculate)
{

    if (step <  0) 
    {
        throw std::invalid_argument("Requested negative element");
    }
    else if (!step) 
    {
        return 0;
    }

    return recalculate ? countNthFibonacci(static_cast<unsigned>(step)) : getCachedNthFibonacci(static_cast<unsigned>(step));
}

int getCachedNthFibonacci(unsigned step)/*{{{*/
{
    static std::vector<unsigned> cache{0, 1};

    if (step >= cache.size()) 
    {
        cache.reserve(step);
        auto begin = cache.cend() -2;
        auto end = cache.cbegin() + step;

        std::transform(begin + 1, end, begin, std::back_inserter(cache), [](unsigned lhs, unsigned rhs) {
                return lhs + rhs;
                });
    }

    return cache[step];
}/*}}}*/

int countNthFibonacci(int step)/*{{{*/
{
    int first = 0, second = 1, result = 0;

    for (int i = 0; i < step; ++i) {
        result = first + second;
        second = first;
        first = result;
    }

    return result;
}/*}}}*/
