#define BOOST_TEST_MODULE soundex test
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <iostream>

struct Fixture
{
    Fixture() { std::cout << "Fixture()" << '\n'; }
    ~Fixture() { std::cout << "~Fixture()" << '\n'; }
};
BOOST_FIXTURE_TEST_SUITE(testing, Fixture)


BOOST_AUTO_TEST_CASE(unitOfWork_scenario_result)
{
    BOOST_CHECK_EQUAL(1, 1);
}

BOOST_AUTO_TEST_CASE(unitOfWork_scenario_result2)
{
    BOOST_CHECK_EQUAL(2, 2);
}

BOOST_AUTO_TEST_SUITE_END();
