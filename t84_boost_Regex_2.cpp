#include <iostream>
#include <boost/regex.hpp>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        std::cout << "Usage: " << argv[0] << " <regex_to_be_matched>\n";
        return -1;
    }

    boost::cmatch match;
    boost::regex r(R"foo((MDU|STATUS)_(\d{2})_(\d{3}))foo");

    if (!boost::regex_match(argv[1], match, r)) 
    {
        std::cout << "Regex doesn't match!" << '\n';
        return 1;
    }

    std::cout << "First number group: " << match[1] << '\n';
    std::cout << "Second number group: " << match[2] << '\n';
    std::cout << "Third number group: " << match[3] << '\n';
    std::cout << "Fourth number group: " << match[4] << '\n';

    return 0;
}
