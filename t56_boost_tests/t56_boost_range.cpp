#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/range/irange.hpp>
#include <boost/range.hpp>
#include <iostream>
#include <vector>


bool isOdd(int value)
{
    return value % 2;
}


int main()
{
    std::vector<int> numbers {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

   std::cout << "\nPrint whole sequence backwards:\n";
    boost::copy(numbers | boost::adaptors::reversed, std::ostream_iterator<int>(std::cout, ", "));

    std::cout << "\nPrint odd numbers backwards:\n";
    boost::copy(numbers | boost::adaptors::reversed | boost::adaptors::filtered(isOdd), std::ostream_iterator<int>(std::cout, ", "));

    std::cout << "\nPrint odd numbers backwards with replaces:\n";
    boost::copy(numbers 
                | boost::adaptors::reversed 
                | boost::adaptors::filtered(isOdd)
                | boost::adaptors::replaced_if(isOdd, 0)
                , std::ostream_iterator<int>(std::cout, ", "));

    std::cout << "\nPrint numbers unsing C++11 initializer list\n";
    for(int i : {1,2,3,4,5,6,7})
        std::cout << i << ", ";
    std::cout << '\n';

    std::cout << "\nPrint irange numbers with transformation:\n";
    auto map = boost::adaptors::transformed;
    using fn = std::function<int(int)>;

    boost::copy(boost::irange(1, 10)
                | map(fn([](int value) { return value * 2; }))
                | map(fn([](int value) { return value + 1; }))
                | map(fn([](int value) { return value * 3; }))
                , std::ostream_iterator<int>(std::cout, ", "));
    std::cout << '\n';
    /* ToDo: sprawdzić czy z boost::lamda też jest konieczne wrapowanie w std::function (skramer, Thu 26 Jun 2014 05:50:33 PM CEST) */
    return 0;
 }
