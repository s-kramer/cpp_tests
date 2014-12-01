#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>

struct F {
    int i;
    F(void) : i(0) { BOOST_TEST_MESSAGE( "setup fixture" ); }
    ~F(void) { BOOST_TEST_MESSAGE("teardown fixture"); }
};

BOOST_FIXTURE_TEST_CASE( example_test, F)
{
    BOOST_CHECK_EQUAL(i, 1);
}

BOOST_FIXTURE_TEST_CASE( second_example_test, F)
{
    BOOST_CHECK_EQUAL(i, 0);
}

BOOST_AUTO_TEST_CASE (nullary_test_case)
{
    BOOST_CHECK (true);
}

BOOST_FIXTURE_TEST_SUITE(examplary_tests, F)

    BOOST_AUTO_TEST_CASE(first)
    {
        BOOST_CHECK_EQUAL(i, 1);
    }

    BOOST_AUTO_TEST_CASE(second)
    {
        BOOST_CHECK_EQUAL(i, 0);
        i++;
    }


    BOOST_AUTO_TEST_CASE(third)
    {
        BOOST_CHECKPOINT("preparing to run third test in examplary_tests test suite");
        BOOST_TEST_MESSAGE("This tests the incremented fixture variable");
        BOOST_CHECK_EQUAL(i, 1);
    }

BOOST_AUTO_TEST_SUITE_END()
