#ifndef SOUNDEX
#define SOUNDEX
#include <string>

class Soundex
{
  public:
    std::string encode(const std::string& word) const;

  private:
    std::string padd(const std::string& word) const;
};
#endif
