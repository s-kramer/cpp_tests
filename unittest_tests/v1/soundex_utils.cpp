#include "soundex_utils.h"

std::string toLower(const std::string& word)
{
    auto lowerWord = word;
    for (auto& letter : lowerWord)
    {
        letter = std::tolower(letter);
    }

    return lowerWord;
}

bool isVowel(const char letter)
{
    static auto vowelsSet = std::string("aeiouy");

    return vowelsSet.find(letter) != vowelsSet.npos;
}

