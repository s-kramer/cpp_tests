#include "soundex.h"
#include "soundex_utils.h"
#include <unordered_map>

std::string Soundex::encode(const std::string& word) const
{
    auto lowerWord = toLower(word);
    auto encodedHead = encodeHead(head(lowerWord));
    auto encodedTail = encodeTail(tail(lowerWord));
    return zeroPad(std::string(1, encodedHead) + encodedTail);
}

char Soundex::encodeHead(const char head) const
{
    lastEncodedLetter = encodeSingleLetter(std::tolower(head));
    return std::toupper(head);
}

std::string Soundex::encodeTail(const std::string& word) const
{
    auto encoded = std::string("");

    for (auto letter : word)
    {
        if (!isTailComplete(encoded)) 
            tryAddSingleLetter(encoded, letter);
    }
    return encoded;
}

void Soundex::tryAddSingleLetter(std::string& currentEncoding, char letter) const
{
    auto candidate = encodeSingleLetter(letter);
    if (isLetterValidCandidate(candidate))
    {
        lastEncodedLetter = candidate;
        currentEncoding += lastEncodedLetter;
    }
    else {
        lastIgnoredLetter = letter;
    }
}

bool Soundex::isTailComplete(const std::string& word) const
{
    return word.length() == MAX_WORD_LENGTH - 1;
    std::string test("test");
}

bool Soundex::isLetterValidCandidate(const char candidate) const
{
    return candidate != NotALetter &&
           (candidate != lastEncodedLetter || isVowel(lastIgnoredLetter));
}

char Soundex::head(const std::string& word) const
{
    return word.empty() ? NotALetter : word.front();
}

std::string Soundex::tail(const std::string& word) const
{
    return word.length() < 2 ? "" : word.substr(1);
}

std::string Soundex::zeroPad(const std::string& word) const
{
    auto zerosNeeded = MAX_WORD_LENGTH - word.length();

    if (zerosNeeded > 0)
    {
        return word + std::string(zerosNeeded, '0');
    }

    return word;
}

char Soundex::encodeSingleLetter(const char letter) const
{
    static auto characterMappings = std::unordered_map<char, char>{
        {'b', '1'}, {'f', '1'}, {'p', '1'}, {'f', '1'},
        {'c', '2'}, {'g', '2'}, {'j', '2'}, {'k', '2'}, {'q', '2'}, 
                    {'s', '2'}, {'x', '2'}, {'x', '2'},
        {'d', '3'}, {'t', '3'}, 
        {'l', '4'}, 
        {'m', '5'}, {'n', '5'}, 
        {'r', '6'}
    };

    auto digitIt = characterMappings.find(letter);

    if (digitIt != characterMappings.end())
    {
        return digitIt->second;
    }

    return NotALetter;
}
