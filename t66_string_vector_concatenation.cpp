#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <boost/bind.hpp>
#include <numeric>

int main()
{
    std::string hello("Hello world");
    std::vector<std::string> v(10, hello);

    std::string result;

    // std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, " "));

    class stringConcatenater
    {
    public:
      std::string operator()(const std::string& rhs) { return result += rhs; }
      std::string getResult(void) { return result; }

    private:
        std::string result;
    };

    stringConcatenater s = std::for_each(v.begin(), v.end(), stringConcatenater());
    std::string accumulation_result = std::accumulate(v.begin(), v.end(), std::string(""));

    std::ostringstream ostream_result;
    std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>( ostream_result , ", "));

    std::cout << s.getResult() << '\n';
    std::cout << accumulation_result << '\n';
    std::cout << ostream_result.str() << '\n';

    return 0;
}



