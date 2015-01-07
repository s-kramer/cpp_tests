#include "soundex.h"
#define BOOST_TEST_MODULE soundex test
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <string>

struct SoundexFixture
{
    Soundex s;
};

BOOST_FIXTURE_TEST_SUITE(single_letters, SoundexFixture);

BOOST_AUTO_TEST_CASE(Encode_SingleLetterWord_RetainsTheSoleLetter)
{
    BOOST_CHECK_EQUAL(s.encode("A"), "A000");
}

BOOST_AUTO_TEST_CASE(
    Encode_PassSingleLetterWord_AddsPaddingToEnsure4LetterWord)
{
    BOOST_CHECK_EQUAL(s.encode("I"), "I000");
}

BOOST_AUTO_TEST_CASE(
    Encode_PassTwoLetterWord_RetainFirstEncodeSecondAndPadToWholeWord)
{
    BOOST_CHECK_EQUAL(s.encode("Ab"), "A100");
    BOOST_CHECK_EQUAL(s.encode("Ax"), "A200");
    BOOST_CHECK_EQUAL(s.encode("Am"), "A500");
}

BOOST_AUTO_TEST_CASE(
    Encode_PassUnrecognizedCharacter_IgnoresUnrecognizedCharacter)
{
    BOOST_CHECK_EQUAL(s.encode("A#"), "A000");
}

BOOST_AUTO_TEST_CASE(
    Encode_PassMoreThanFourCharWord_TrimmsToFourLetterWord)
{
    BOOST_CHECK_EQUAL(s.encode("Abcdef"), "A123");
}

BOOST_AUTO_TEST_CASE(
    Encode_PassThreeLetterWord_RetainsFirstAndEncodesTwoNextAndPaddsToWholeWorld)
{
    BOOST_CHECK_EQUAL(s.encode("Abc"), "A120");
}

BOOST_AUTO_TEST_CASE(Encode_PassVowelLikeLetters_IgnoresVowelsAndWHY)
{
    BOOST_CHECK_EQUAL(s.encode("Baeiouhycdl"), "B234");
}

BOOST_AUTO_TEST_CASE(
    Encode_PassLettersWithTheSameEncoding_IgnoresTheDuplicateLetters)
{
    BOOST_CHECK_EQUAL(s.encodeSingleLetter('b'),
                      s.encodeSingleLetter('f'));
    BOOST_CHECK_EQUAL(s.encodeSingleLetter('c'),
                      s.encodeSingleLetter('g'));
    BOOST_CHECK_EQUAL(s.encodeSingleLetter('d'),
                      s.encodeSingleLetter('t'));

    BOOST_CHECK_EQUAL(s.encode("Abfcgtd"), "A123");
}

BOOST_AUTO_TEST_CASE(
    Encode_WordWithTwoLettersSeparatedByHAndW_SurrouningLettersGetEncodedOnce)
{
    BOOST_CHECK_EQUAL(s.encode("Abhfcwgdt"), "A123");
}

BOOST_AUTO_TEST_CASE(
    Encode_WordWithTwoLettersSeparatedByVowel_SurrouningLettersGetEncodedTwice)
{
    BOOST_CHECK_EQUAL(s.encode("Abefcigdt"), "A112");
    BOOST_CHECK_EQUAL(s.encode("Acigdet"), "A223");
}

BOOST_AUTO_TEST_CASE(Encode_PassCamelCasedWord_IgnoresLettersCase)
{
    BOOST_CHECK_EQUAL(s.encode("aBcD"), s.encode("AbCd"));
}

BOOST_AUTO_TEST_CASE(
    Encode_PassTheSameLettersWithDifferentCase_IgnoreDuplicates)
{
    BOOST_CHECK_EQUAL(s.encode("AbBCcDdeE"), "A123");
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

BOOST_AUTO_TEST_CASE(Encoding_PassEmptyString_Unknown)
{
    BOOST_CHECK_EQUAL(s.encode(""), "*000");
}

BOOST_AUTO_TEST_SUITE_END();
