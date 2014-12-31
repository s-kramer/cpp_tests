#include "frog_river_one.h"
#include <vector>
#include <algorithm>
#include <iostream>

int square(int sum, int val)
{
    return sum + val * val;
}

void make_unique(std::vector<int> &A)
{
    /* Eliminate duplications */
    std::vector<int>::iterator it;
    it = std::unique(A.begin(), A.end());
    A.resize(std::distance(A.begin(), it));
}


bool is_continuous(std::vector<int> A)
{
    std::sort(A.begin(), A.end());
    make_unique(A);
    std::vector<int>::iterator begin = A.begin(), end = A.end();
    int size = A.size();

    unsigned long int sum = std::accumulate(begin, end, 0);
    unsigned long int sum_squared = std::accumulate(begin, end, 0, square);

    unsigned expected_sum = static_cast<float>(*std::max_element(begin, end) + *std::min_element(begin, end)) / 2 * size;
    unsigned expected_squared_sum =
        size * (size + 1) * (2 * size + 1) / 6;

    if (sum != expected_sum || sum_squared != expected_squared_sum) {
        return false;
    }
    return true;

}

int solution(int X, std::vector<int> &A)
{
/*
 *     [> Check if the given vector is continuous <]
 *     if(!is_continuous(A)) {
 *         return -1;
 *     }
 * 
 *     int result = std::find(A.begin(), A.end(), X) - A.begin();
 *     if (A[result] == X) {
 *         return result;
 *     }
 */
    std::vector<int>::iterator it;
    std::vector<int> occupance(X, 0);
    for(it = A.begin(); it != A.end(); it++) {
        occupance[*it - 1] = 1;
        if (std::accumulate(occupance.begin(), occupance.end(), 0) == (int)occupance.size()) {
            return it - A.begin();
        }
    }
    return -1;
};
