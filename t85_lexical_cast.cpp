#include <iostream>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <algorithm>
#include <string>

int main(int argc, char *argv[])
{
    if (argc < 2) 
    {
        std::cout << "Usage: " << argv[0] << " <numbers>\n";
        return -1;
    }
    std::vector<int> v;
    v.reserve(argc);

    std::transform(argv[1], argv[argc], std::back_inserter(v), boost::lexical_cast<int>);

    // std::string input;

    // while (std::cin >> input) {
        // std::cout << boost::lexical_cast<int>(input) << '\n';
    // }

    return 0;
}
