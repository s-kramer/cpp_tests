#include "fibonacci.h"
#define BOOST_TEST_MODULE fibonacci_generator
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( fibonacci_numbers_generation_cached )
{
    for (int i = 0; i < 1000; ++i) {
        BOOST_CHECK_THROW( getNthFibonacci(-1, false), std::invalid_argument);
        BOOST_CHECK_EQUAL( getNthFibonacci(0, false), 0); 
        BOOST_CHECK_EQUAL( getNthFibonacci(1, false), 1); 
        BOOST_CHECK_EQUAL( getNthFibonacci(2, false), 1); 
        BOOST_CHECK_EQUAL( getNthFibonacci(3, false), 2); 
        BOOST_CHECK_EQUAL( getNthFibonacci(4, false), 3); 
        BOOST_CHECK_EQUAL( getNthFibonacci(5, false), 5); 
        BOOST_CHECK_EQUAL( getNthFibonacci(6, false), 8); 
        BOOST_CHECK_EQUAL( getNthFibonacci(7, false), 13); 
        BOOST_CHECK_EQUAL( getNthFibonacci(8, false), 21); 
        BOOST_CHECK_EQUAL( getNthFibonacci(9, false), 34); 
        BOOST_CHECK_EQUAL( getNthFibonacci(10, false), 55); 
        BOOST_CHECK_EQUAL( getNthFibonacci(11, false), 89); 
        BOOST_CHECK_EQUAL( getNthFibonacci(12, false), 144); 
        BOOST_CHECK_EQUAL( getNthFibonacci(13, false), 233); 
        BOOST_CHECK_EQUAL( getNthFibonacci(14, false), 377); 
        BOOST_CHECK_EQUAL( getNthFibonacci(15, false), 610); 
        BOOST_CHECK_EQUAL( getNthFibonacci(16, false), 987); 
        BOOST_CHECK_EQUAL( getNthFibonacci(17, false), 1597); 
        BOOST_CHECK_EQUAL( getNthFibonacci(18, false), 2584); 
        BOOST_CHECK_EQUAL( getNthFibonacci(19, false), 4181); 
        BOOST_CHECK_EQUAL( getNthFibonacci(18, false), 2584); 
    }
}

BOOST_AUTO_TEST_CASE( fibonacci_numbers_generation_recalculated )
{
    for (int i = 0; i < 1000; ++i) {
        BOOST_CHECK_THROW( getNthFibonacci(-1, true), std::invalid_argument);
        BOOST_CHECK_EQUAL( getNthFibonacci(0, true), 0); 
        BOOST_CHECK_EQUAL( getNthFibonacci(1, true), 1); 
        BOOST_CHECK_EQUAL( getNthFibonacci(2, true), 1); 
        BOOST_CHECK_EQUAL( getNthFibonacci(3, true), 2); 
        BOOST_CHECK_EQUAL( getNthFibonacci(4, true), 3); 
        BOOST_CHECK_EQUAL( getNthFibonacci(5, true), 5); 
        BOOST_CHECK_EQUAL( getNthFibonacci(6, true), 8); 
        BOOST_CHECK_EQUAL( getNthFibonacci(7, true), 13); 
        BOOST_CHECK_EQUAL( getNthFibonacci(8, true), 21); 
        BOOST_CHECK_EQUAL( getNthFibonacci(9, true), 34); 
        BOOST_CHECK_EQUAL( getNthFibonacci(10, true), 55); 
        BOOST_CHECK_EQUAL( getNthFibonacci(11, true), 89); 
        BOOST_CHECK_EQUAL( getNthFibonacci(12, true), 144); 
        BOOST_CHECK_EQUAL( getNthFibonacci(13, true), 233); 
        BOOST_CHECK_EQUAL( getNthFibonacci(14, true), 377); 
        BOOST_CHECK_EQUAL( getNthFibonacci(15, true), 610); 
        BOOST_CHECK_EQUAL( getNthFibonacci(16, true), 987); 
        BOOST_CHECK_EQUAL( getNthFibonacci(17, true), 1597); 
        BOOST_CHECK_EQUAL( getNthFibonacci(18, true), 2584); 
        BOOST_CHECK_EQUAL( getNthFibonacci(19, true), 4181); 
        BOOST_CHECK_EQUAL( getNthFibonacci(18, true), 2584); 
    }
}
