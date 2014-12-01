#include <iostream>
#include <vector>
#include <boost/iterator/counting_iterator.hpp>
#include <algorithm>

class Converter
{
public:
    unsigned operator()(unsigned arg) { return arg + 10; }
private:
};

int main()
{
    std::vector<unsigned> result;
    std::transform(boost::counting_iterator<unsigned>(0), boost::counting_iterator<unsigned>(256), std::back_inserter(result), Converter());
    std::copy(result.begin(), result.end(), std::ostream_iterator<unsigned>(std::cout, " "));
    return 0;
}
