#include <iostream>
#include <regex>
#include <string>

/* Check how to match all the digits inside of a string. 
 * Previouselly, the searches were not lazy (no ? sign in \\w+?) 
 * and they matched too many characters (\\w == [a-zA-Z0-9)
 */

int main()
{
    std::string s("aaabbbccd123456eeffgg");
    std::smatch match;
    // This one also works but matches more than is required
    // std::regex braced_regex("(\\D+)(\\d{2,})(\\D+)");
    std::regex braced_regex("([[:alpha:]]+?)(\\d+)([[:alpha:]]+?)");
    std::regex plus_regex("(\\w+?)(\\d+)(\\w+?)");

    auto printer = [](auto& match) {
            std::ssub_match sub(match);
            std::string match_substring(sub.str());
            std::cout <<  match_substring << '\n';
    };

    std::regex_match(s, match, braced_regex);
    std::cout << "Number of braced matches: " << match.size() << '\n';  
    std::for_each(match.begin(), match.end(), printer);

    std::regex_match(s, match, plus_regex);
    std::cout << "Number of plus matches: " << match.size() << '\n';  
    std::for_each(match.begin(), match.end(), printer);
    return 0;
}
