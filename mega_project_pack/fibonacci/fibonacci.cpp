#include "fibonacci.h"

int getNthFibonacci(int step)
{
    if (step <  0) 
    {
        throw std::invalid_argument("Requested negative element");
    }
    else if (!step) 
    {
        return 0;
    }

    return (step < MAX_CACHE) ? getCachedNthFibonacci(step) : countNthFibonacci(step);
}

int getCachedNthFibonacci(int step)/*{{{*/
{
    static std::vector<int> cache(MAX_CACHE, 0);

    int cached_value = cache[step];
    if (cached_value) 
    {
        return cached_value;
    }

    int result = countNthFibonacci(step);

    cache[step] = result;

    return result;
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
