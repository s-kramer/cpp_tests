#include <iostream>
#include <boost/bind.hpp>
#include <algorithm>
#include <vector>
#include <boost/foreach.hpp>
#include <boost/iterator/counting_iterator.hpp>
 
int doubleValue (int i) 
{
    return i * 2;
}

int main()
{
    std::vector<int> numbers;
    numbers.reserve(10);

    std::transform(boost::counting_iterator<int>(0), boost::counting_iterator<int>(10), std::back_inserter(numbers), boost::bind(&doubleValue, _1));

    std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(std::cout, "\n"));
    return 0;
}
