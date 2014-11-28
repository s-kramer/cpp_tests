#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string s("some text");
    std::string::iterator i = std::find(s.begin(), s.end(), ' ');
    std::cout << "Found: \"" << *i << "\" at location " << i - s.begin() << '\n';
    return 0;
}
