#include <stdio.h>
#include <stdlib.h>
#include "smallest_diff.h"

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        printf("Usage: %s {args..}\n", argv[0]);
        return -1;
    }

    // The array of processed ints
    int A[argc-1];

    int i = 0, p = 0, N = argc -1;

    for (i = 1; i < argc; i++) {
        A[i-1] = atoi(argv[i]);
    }

    long int smallest_diff = count_abs_difference(A, N, p);

    printf("Lowest absolute difference: %li for index p: %i\n", smallest_diff, p);
    return 0;
}
