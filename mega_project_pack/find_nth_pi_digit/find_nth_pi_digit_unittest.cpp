#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE examples
#include <boost/test/unit_test.hpp>
#include "find_nth_pi_digit.h"

BOOST_AUTO_TEST_CASE(pi_digits)
{
    BOOST_CHECK_EQUAL(getPiNthDigit(0), 3);
    BOOST_CHECK_CLOSE(5.0001, 5 + 0.001, 0.02);
}
