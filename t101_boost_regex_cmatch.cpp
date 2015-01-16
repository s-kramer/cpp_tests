#include <iostream>
#include <string>
#include <boost/regex.hpp>

int main()
{
    boost::cmatch matcher;
    std::string stringToMatch{"some string"};
    const char* regexData = ".*string$";
    boost::regex regexpr(regexData);
    std::cout << std::boolalpha << boost::regex_match(stringToMatch.data(), matcher, regexpr) << '\n';
    return 0;
}
