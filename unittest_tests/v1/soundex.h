#ifndef SOUNDEX
#define SOUNDEX
#include <string>

class Soundex
{
  public:
    /*{{{*/ Soundex(void)
        : lastEncodedLetter(NotALetter), lastIgnoredLetter(NotALetter){};
    ~Soundex(void) = default;

    Soundex(Soundex&) = delete;
    Soundex& operator=(Soundex&) = delete;

    Soundex(Soundex&&) = delete;
    Soundex& operator=(Soundex&&) = delete;
    /*}}}*/

    std::string encode(const std::string& word) const;
    char encodeSingleLetter(char letter) const;

  private:
    static constexpr auto MAX_WORD_LENGTH = 4;
    static constexpr auto NotALetter = '*';

    std::string zeroPad(const std::string& word) const;

    char head(const std::string& word) const;
    char encodeHead(const char word) const;

    std::string tail(const std::string& word) const;
    std::string encodeTail(const std::string& word) const;

    bool isTailComplete(const std::string& word) const;
    bool isLetterValidCandidate(const char candidate) const;
    void tryAddSingleLetter(std::string& currentEncoding,
                            char candidate) const;

    mutable char lastEncodedLetter;
    mutable char lastIgnoredLetter;
};

#endif
