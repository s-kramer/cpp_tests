#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

std::vector<std::string> split(const std::string &str, char delim = ' ')
{
    std::stringstream ss(str);
    std::string item;
    std::vector<std::string> elements; 
    while(std::getline(ss, item, delim))
    {
        elements.push_back(item);
    }
    return elements;
}

std::vector<std::string> splitBoost(const std::string &str, std::string delim = " ")
{
    std::vector<std::string> result;
    boost::split(result, str, boost::algorithm::is_any_of(delim), boost::token_compress_on);
    return result;
}

std::string reverse_word_order(std::string &str)
{
    if (str == "") {
        return str;
    }

    std::reverse(str.begin(), str.end());
    std::vector<std::string> splitted_words = split(str);
    for (std::vector<std::string>::iterator i = splitted_words.begin(); i != splitted_words.end(); i++) {
        std::reverse(i->begin(), i->end());
    }
    std::stringstream ss;
    std::copy(splitted_words.begin(), splitted_words.end() - 1, std::ostream_iterator<std::string>(ss, " "));
    ss << splitted_words.back();
    str = ss.str();
    return str;
}

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <string_to_reverse>\n";
        return -1;
    }
    std::cout << "Before reversion: " << argv[1] << '\n';
    std::string reversed_string(argv[1]);
    std::cout << "After reversion:  " << reverse_word_order(reversed_string) << '\n';

    std::vector<std::string> temp = split(argv[1]);
    std::cout << "\nSplitted argument:\n";
    std::copy(temp.begin(), temp.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
    temp = splitBoost(argv[1], " ");
    std::cout << "\nBoost splitted argument:\n";
    std::copy(temp.begin(), temp.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

    return 0;
}
