#include "smallest_diff.h"
#include <stdlib.h>

long int count_abs_difference(int *A, int N,
                              // Splitting pointer
                              int &p)
{
    int i = 0;
    int sum = 0;

    for (i = 0; i < N; i++) {
        sum += A[i];
    }

    // Starting pointer
    p = 0;

    // Sum used in the loop, the upper half
    int temp_sum = sum - A[0];

    int lower_half = A[0], current_lowest = abs(temp_sum - A[0]);

    // Start at p + 1 value, traverse until last element
    for (int i = 1; i < N - 1; i++) {
        lower_half += A[i];
        temp_sum -= A[i];

        if (abs( temp_sum - lower_half ) < current_lowest) {
            current_lowest = abs( temp_sum - lower_half );
            p = i;
        }

    }

    return current_lowest;
}
