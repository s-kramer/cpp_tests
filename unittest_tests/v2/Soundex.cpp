#include "Soundex.h"
#include <stdexcept>
#include <unordered_map>
#include <cctype>
#include <iostream>

std::string Soundex::encode(const std::string& word) const
{
    bool test = false;
    test =  word.length();

    if (word.empty())
    {
        throw std::invalid_argument("Empty word provided");
    }


    auto encodedHead = encodeHead(head(word));
    auto encodedTail = encodeTail(tail(word));
    return padd(encodedHead + encodedTail);
}

std::string Soundex::padd(const std::string& word) const
{
    auto zerosNeeded = MAX_WORD_LENGTH - word.length();
    if (zerosNeeded > 0)
    {
        return word + std::string(zerosNeeded, '0');
    }

    return word;
}

char Soundex::head(const std::string& word) const
{
    return std::toupper(word.front());
}

std::string Soundex::tail(const std::string& word) const
{
    if (word.length() >= 2)
    {
        return word.substr(1);
    }

    return "";
}

std::string Soundex::encodeHead(const char head) const
{
    lastEncodedCharacter = getLetterEncoding(head);
    return std::string(1, head);
}

std::string Soundex::encodeTail(const std::string& word) const
{
    auto encoded = std::string{ "" };

    for (auto letter : word)
    {
        if (!isEncodingComplete(encoded))
        {
            encodeSingleLetter(encoded, letter);
        }
    }

    return encoded;
}

bool Soundex::isEncodingComplete(const std::string& word) const
{
    return word.length() >= MAX_WORD_LENGTH - 1;
}

void Soundex::encodeSingleLetter(std::string& encodedWord,
                                 const char letter) const
{
    auto candidate = getLetterEncoding(letter);
    if (isCandidateSuitable(candidate))
    {
        lastEncodedCharacter = candidate;
        encodedWord += candidate;
    }
}

bool Soundex::isCandidateSuitable(const char candidate) const
{
    return candidate != NOT_A_LETTER &&
           (candidate != lastEncodedCharacter ||
            isVowel(lastIngoredCharacter));
}

bool Soundex::isVowel(const char letter) const
{
    auto vowels = std::string{ "aeiouy" };
    return vowels.find(letter) != vowels.npos;
}

char Soundex::getLetterEncoding(const char letter) const
{
    static auto lettersEncoding = /*{{{*/
        std::unordered_map<char, char>{ { 'b', '1' },
                                        { 'f', '1' },
                                        { 'p', '1' },
                                        { 'v', '1' },
                                        { 'c', '2' },
                                        { 'g', '2' },
                                        { 'j', '2' },
                                        { 'k', '2' },
                                        { 'q', '2' },
                                        { 's', '2' },
                                        { 'x', '2' },
                                        { 'z', '2' },
                                        { 'd', '3' },
                                        { 't', '3' },
                                        { 'l', '4' },
                                        { 'm', '5' },
                                        { 'n', '5' },
                                        { 'r', '6' } }; /*}}}*/

    auto encodedLetter = lettersEncoding.find(std::tolower(letter));

    if (encodedLetter != lettersEncoding.end())
    {
        return encodedLetter->second;
    }

    lastIngoredCharacter = letter;
    return NOT_A_LETTER;
}
