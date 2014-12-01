#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE examples
#include <boost/test/included/unit_test.hpp>
#include <utility>

struct MyFixture {
     MyFixture() { i = new int; *i = 0; }
     ~ MyFixture() { delete i; }

    int* i;
};

BOOST_AUTO_TEST_CASE( test_case1 )
{
    MyFixture f;

    // do something involving f.i
}

BOOST_AUTO_TEST_CASE( test_case2 )
{
    MyFixture f;

    // do something involving f.i
}
