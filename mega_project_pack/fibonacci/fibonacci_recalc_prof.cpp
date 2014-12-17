#include "fibonacci.h"

int main()
{
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 100; ++j) {
            getNthFibonacci(j, true);
        }
    }
    return 0;
}
