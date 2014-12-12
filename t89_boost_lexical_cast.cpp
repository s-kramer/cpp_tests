#include <iostream>
#include <boost/lexical_cast.hpp>
#include <string>
#include <boost/regex.hpp>

int main()
{
    std::string s("aaabbbccc321234ddeeff");

    boost::regex pattern("(\\w+)(\\d{2,})(\\w*)");

    boost::smatch match;
    if(boost::regex_match(s, match, pattern))
    {
        std::cout << "Number of matches made: " <<  match.size() << '\n';  
        std::for_each(match.begin(), match.end(), [](auto& match){
                boost::ssub_match sub_match = match;
                std::string matched_substring(sub_match.str());
                std::cout << "Match made: " <<  matched_substring << '\n'; 
                });
    }
    else {
        std::cout <<  "integer not found in string" << '\n'; 
    }

    return 0;
}
