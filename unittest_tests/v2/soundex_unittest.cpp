// #include "soundex.h"
#define BOOST_TEST_MODULE soundex test
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "Soundex.h"
#include <stdexcept>

struct Soundex_fixture
{
    Soundex s;
};

BOOST_FIXTURE_TEST_SUITE(encode, Soundex_fixture)

BOOST_AUTO_TEST_CASE(encode_passEmptyString_throwException)
{
    BOOST_CHECK_THROW(s.encode(""), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(encode_passOneLetterWord_paddToWholeWord)
{
    BOOST_CHECK_EQUAL("A000", s.encode("A"));
}

BOOST_AUTO_TEST_CASE(
    encode_replaceLetterWithDigit_RetainsFirstEncodesSecondAndPadds)
{
    BOOST_CHECK_EQUAL("A100", s.encode("Ab"));
    BOOST_CHECK_EQUAL("A200", s.encode("Ac"));
}

BOOST_AUTO_TEST_CASE(encode_FourLetterWord_RetainsFirstAndEncodesRest)
{
    BOOST_CHECK_EQUAL("A123", s.encode("Abcd"));
}

BOOST_AUTO_TEST_CASE(
    encode_TooLongWord_RetainsFirstAndEncodesUntilFullWord)
{
    BOOST_CHECK_EQUAL("A123", s.encode("Abcdm"));
}

BOOST_AUTO_TEST_CASE(encode_WordWithDuplicateLetters_IgnoresTheDuplicates)
{
    BOOST_CHECK_EQUAL(s.getLetterEncoding('b'), s.getLetterEncoding('f'));
    BOOST_CHECK_EQUAL(s.getLetterEncoding('c'), s.getLetterEncoding('g'));
    BOOST_CHECK_EQUAL(s.getLetterEncoding('d'), s.getLetterEncoding('d'));
    BOOST_CHECK_EQUAL("A123", s.encode("Abfcgdt"));
}

BOOST_AUTO_TEST_CASE(
    encode_WordWithLettersSeparatedByHAndW_LettersGetEncodedOnce)
{
    BOOST_CHECK_EQUAL("A123", s.encode("Abhfcwgdht"));
}

BOOST_AUTO_TEST_CASE(encode_LettersSeparatedByVowels_GetCodedTwice)
{
    BOOST_CHECK_EQUAL("A122", s.encode("Abceg"));
}

BOOST_AUTO_TEST_CASE(encode_FirstLetterIsFollowedByItsDuplicate_DuplicateGetsIngored)
{
    BOOST_CHECK_EQUAL("B234", s.encode("Bfcdl"));
}

BOOST_AUTO_TEST_CASE(encode_FirstLetterFollowedByHAndWFollowedByDuplicate_DuplicateGetsIgnored)
{
    BOOST_CHECK_EQUAL("B234", s.encode("Bhfcdl"));
    BOOST_CHECK_EQUAL("B234", s.encode("Bwfcdl"));
}

BOOST_AUTO_TEST_CASE(encode_FirstLetterFollowedByVowelFollowedByDuplicate_DuplicateGetsCodedTwice)
{
    BOOST_CHECK_EQUAL("B123", s.encode("Befcdl"));
}

BOOST_AUTO_TEST_CASE(encode_WordsWithDifferentCases_IgnoredCasing)
{
    BOOST_CHECK_EQUAL(s.encode("AbCdLmR"), s.encode("aBcDlMr"));
}

BOOST_AUTO_TEST_CASE(Encoding_ConfirmationTests_AllPass)
{
    BOOST_CHECK_EQUAL(s.encode("Robert"), "R163");
    BOOST_CHECK_EQUAL(s.encode("Robert"), s.encode("Rupert"));
    BOOST_CHECK_EQUAL(s.encode("Rubin"), "R150");
    BOOST_CHECK_EQUAL(s.encode("Ashcraft"), "A261");
    BOOST_CHECK_EQUAL(s.encode("Ashcraft"), s.encode("Ashcroft"));
    BOOST_CHECK_EQUAL(s.encode("Tymczak"), "T522");
}

BOOST_AUTO_TEST_CASE(Encoding_ConfirmationTests_AllPass2)
{
    BOOST_CHECK_EQUAL(s.encode("Pfister"), "P236");
}
BOOST_AUTO_TEST_SUITE_END()
