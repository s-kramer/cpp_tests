#include <boost/range/numeric.hpp>
#include <boost/range.hpp>
#include <iostream>
#include <vector>
int main()
{
    std::vector<int> a{0, 1, 2, 3, 4};
    std::vector<int> b{5, 4, 2, 3, 1};
 
    /* Boost ranges? */
    // boost::range boost::begin(a);
    int r1 = boost::inner_product(a, b, 0);
    std::cout << "Inner product of a and b: " << r1 << '\n';
 
    int r2 = boost::inner_product(a, b, 0, std::plus<int>(), std::equal_to<int>());
    std::cout << "Number of pairwise matches between a and b: " <<  r2 << '\n';
}
