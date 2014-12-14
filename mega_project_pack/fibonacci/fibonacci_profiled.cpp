#include "fibonacci.h"

int main()
{
    int j = 0;
    for (int i = 0; i < 100; ++i) {
        j = getNthFibonacci(i % 20);
    }
    return 0;
}
