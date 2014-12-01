#include <iostream>
#include <boost/regex.hpp>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        std::cout << "Usage: " << argv[0] << " <string_to_be_matched>\n";
        return -1;
    }

    boost::smatch what;
    boost::regex regExpr("(MDU|STATUS)_\\d{2}_(_\\d{2}){2}_aaa", boost::regex_constants::icase);
    std::string argument(argv[1]);
    if (boost::regex_match(argument, what, regExpr))
    {
        std::cout << "Regular expression matches!" << '\n';
    }
    else {
        std::cout << "Regular expression doesn't match!" << '\n';
    }

    return 0;
}
