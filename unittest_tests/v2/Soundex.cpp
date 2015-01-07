#include "Soundex.h"
#include <stdexcept>

std::string Soundex::encode(const std::string& word) const
{
    if (word.empty())
    {
        throw std::invalid_argument("Empty word provided");
    }

    return padd(word);
}

std::string Soundex::padd(const std::string& word) const
{
    return word + "000";
}
