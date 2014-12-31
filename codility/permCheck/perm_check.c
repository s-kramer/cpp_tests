#include "perm_check.h"

int solution (std::vector<int> &A)
{
    unsigned long actualchecksum = 0, expected_checksum = 0;
    unsigned long actual_factorial = 1, expected_factorial = 1;
    unsigned long actual_square_sum = 0, expected_square_sum = 0;

    for (unsigned i = 0; i < (unsigned)A.size(); i++) {
        actualchecksum ^= A[i];
        expected_checksum ^= i + 1;
        actual_factorial *= A[i];
        expected_factorial *= i + 1;
        actual_square_sum += A[i] ^ 2;
        expected_square_sum += (i + 1) ^ 2;
    }


    return (expected_checksum == actualchecksum) && (actual_factorial == expected_factorial) && (actual_square_sum == expected_square_sum);


}
/*
 * int solution (std::vector<int> &A)
 * {
 *     int max = *std::max_element(A.begin(), A.end());
 * 
 *     if ((unsigned long)max != A.size()) {
 *         return 0;
 *     }
 *     int min = *std::min_element(A.begin(), A.end());
 * 
 *     [> The type of init argument determines the type of all other elements <]
 *     unsigned long sum = std::accumulate( A.begin(), A.end(), (unsigned long) 0 );
 *     long double expected = (long double)(min + max) / 2 * max;
 * 
 *     return sum == expected;
 * }
 */
