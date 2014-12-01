#include <iostream>
#include <vector>
#include <boost/generator_iterator.hpp>
#include <boost/range/irange.hpp>

class NumberGenerator
{
public:
    typedef int result_type;
    explicit NumberGenerator (int startValue = 0) : value(startValue) {}
    int operator()(){ return value++; }
private:
    int  value;
};

int main()
{
    NumberGenerator numgen;
    boost::generator_iterator_generator<NumberGenerator>::type it = boost::make_generator_iterator(numgen);

    for(int i : boost::irange(10, 20))
        std::cout << *(it++) << " ";
    std::cout << '\n';

    return 0;
}
