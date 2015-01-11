#ifndef SOUNDEX
#define SOUNDEX
#include <string>

class Soundex
{
  public:
    std::string encode(const std::string& word) const;
    char getLetterEncoding(const char letter) const;

  private:
    static constexpr auto MAX_WORD_LENGTH = 4U;
    static constexpr auto NOT_A_LETTER = '*';
    mutable char lastEncodedCharacter  = NOT_A_LETTER;
    mutable char lastIngoredCharacter  = NOT_A_LETTER;

    std::string padd(const std::string& word) const;
    char head(const std::string& word) const;
    std::string tail(const std::string& word) const;
    std::string encodeHead(const char head) const;
    std::string encodeTail(const std::string& word) const;

    bool isEncodingComplete(const std::string& word) const;
    void encodeSingleLetter(std::string& encodedWord, const char letter) const;
    bool isCandidateSuitable(const char letter) const;
    bool isVowel(const char letter) const;
};
#endif
