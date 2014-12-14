#include "fibonacci.h"
#define BOOST_TEST_MODULE fibonacci_generator
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( fibonacci_numbers_generation )
{
    BOOST_CHECK_THROW( getNthFibonacci(-1), std::invalid_argument);
    BOOST_CHECK_EQUAL( getNthFibonacci(0), 0); 
    BOOST_CHECK_EQUAL( getNthFibonacci(1), 1); 
    BOOST_CHECK_EQUAL( getNthFibonacci(2), 1); 
    BOOST_CHECK_EQUAL( getNthFibonacci(3), 2); 
    BOOST_CHECK_EQUAL( getNthFibonacci(4), 3); 
    BOOST_CHECK_EQUAL( getNthFibonacci(5), 5); 
    BOOST_CHECK_EQUAL( getNthFibonacci(6), 8); 
    BOOST_CHECK_EQUAL( getNthFibonacci(7), 13); 
    BOOST_CHECK_EQUAL( getNthFibonacci(8), 21); 
    BOOST_CHECK_EQUAL( getNthFibonacci(9), 34); 
    BOOST_CHECK_EQUAL( getNthFibonacci(10), 55); 
    BOOST_CHECK_EQUAL( getNthFibonacci(11), 89); 
    BOOST_CHECK_EQUAL( getNthFibonacci(12), 144); 
    BOOST_CHECK_EQUAL( getNthFibonacci(13), 233); 
    BOOST_CHECK_EQUAL( getNthFibonacci(14), 377); 
    BOOST_CHECK_EQUAL( getNthFibonacci(15), 610); 
    BOOST_CHECK_EQUAL( getNthFibonacci(16), 987); 
    BOOST_CHECK_EQUAL( getNthFibonacci(17), 1597); 
    BOOST_CHECK_EQUAL( getNthFibonacci(18), 2584); 
    BOOST_CHECK_EQUAL( getNthFibonacci(19), 4181); 
}
