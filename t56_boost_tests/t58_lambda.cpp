#include <boost/lambda/lambda.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>
#include <boost/ref.hpp>
#include <boost/foreach.hpp>
#include <boost/bind.hpp>
#define  foreach_ BOOST_FOREACH
#include <iostream>
#include <vector>
#include <algorithm>

// using namespace boost::lambda;

struct Func{ int operator()(int i)  const { return i * 2; } };

class FuncWithMem
{
public:
    int number;
    FuncWithMem(int initialNumber): number(initialNumber) {}
    bool isEven(int value) { return value % 2; }
    void setNumber(int i) { number = i; }
};

int main()
{
    std::vector<int> numbers(10);
    boost::iota(numbers, 0);
    std::cout << "Vector default using BOOST_FOREACH:\n";
    foreach_(int i, numbers)
    {
        std::cout << i << ", ";
    }
    std::cout << '\n';
    std::cout << "Vector default using foreach + lambda:\n";
    boost::for_each(numbers, std::cout << boost::lambda::constant("\n") << boost::lambda::_1 << ", ");
    std::cout << '\n';
    std::cout << "Double the values and sort descenting:\n";
    boost::for_each(numbers, boost::lambda::_1 = boost::lambda::_1 * 2);
    boost::sort(numbers, boost::lambda::_1 > boost::lambda::_2);
    boost::copy(numbers, std::ostream_iterator<int>(std::cout, ", "));
    std::cout << '\n';
    std::cout << "Test for argument binding:\n";
    int i = 1;
    /* Execute lambda x.(x=2, x+1) rather than lamdba x.(x=2, x+i) */
    std::cout << (boost::lambda::_1 = 2, boost::lambda::_1 + i)(i);
    std::cout << '\n';
    /* Execute lambda x.(x=2, x+i)*/
    std::cout << (boost::lambda::_1 = 2, boost::lambda::_1 + boost::ref(i))(i);
    std::cout << '\n';

    std::cout << "Bind tests:\n";
    Func func;
    // boost::lambda::ret<int>(boost::bind(func, _1))(2);
    std::cout << boost::bind<int>(func, boost::lambda::_1)(2);
    std::cout << '\n';

    FuncWithMem funcWithMem(9);
    std::cout << "Member function bind:\n";
    std::cout << boost::bind<bool>(&FuncWithMem::isEven, funcWithMem, boost::lambda::_1) (2);
    std::cout << '\n';

    std::cout << "Bind lambda with local object (setting number to 2):\n";
    /* This passes funcWithMem as copy */
    boost::bind(&FuncWithMem::setNumber, funcWithMem, boost::lambda::_1) (i);
    std::cout << "FuncWithMem::number copy = " << funcWithMem.number << " (initial: 9)\n";
    /* This passes funcWithMem as ref-to-const */
    boost::bind(&FuncWithMem::setNumber, boost::ref(funcWithMem), boost::lambda::_1) (i);
    std::cout << "FuncWithMem::number ref  = " << funcWithMem.number << " (initial: 9)\n";

    
    return 0;
}
