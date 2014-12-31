#include "perm_check.h"
#include <iostream>

int main()
{
    std::vector<int> v(100000, 1);
    unsigned long sum = 0;

    for (int i = 0; i < 100000; i++) {
        v[i] = i+1;
        sum += i+1;
    }

    unsigned long accumulated_int = std::accumulate(v.begin(), v.end(), (unsigned long)0);
    unsigned long accumulated_double = std::accumulate(v.begin(), v.end(), 0.0);
    double long arith = (double long) (*std::max_element(v.begin(), v.end()) + *std::min_element(v.begin(), v.end())) / 2 * v.size();

    std::cout << "sum: " << sum << "\naccumulated_int: " << accumulated_int << "\naccumulated_double: " << accumulated_double << "\narith: " << arith << '\n';


    return 0;
}
