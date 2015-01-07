// #include "soundex.h"
#define BOOST_TEST_MODULE soundex test
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "Soundex.h"
#include <stdexcept>

BOOST_AUTO_TEST_CASE(encode_passEmptyString_throwException)
{
    Soundex s;

    BOOST_CHECK_THROW(s.encode(""), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(encode_passOneLetterWord_paddToWholeWord)
{
    Soundex s;

    std::string encoded = s.encode("A");

    BOOST_CHECK_EQUAL(encoded, "A000");
}
