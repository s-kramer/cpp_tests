#include <iostream>
#include <boost/iterator/counting_iterator.hpp>
#include <boost/iterator/filter_iterator.hpp>
#include <vector>
#include <algorithm>
#include <boost/bind.hpp>
#include <boost/bind/placeholders.hpp>
#include <boost/function.hpp>
#include <functional>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>

class isUneven {
  public:
    typedef bool result_type;
    bool operator()(int rhs) { return rhs % 2 == 1; }
};

typedef boost::counting_iterator<int> count_iter;

int main() {
    // Counting iterator basic funcitonality
    std::copy(count_iter(0), count_iter(10), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // Counting iterator base member function
    boost::counting_iterator<int> a(5);
    std::cout << a.base() << '\n';

    // Filter iterator basic
    boost::function<bool(int)> unEvenSTLPred =
        boost::bind(std::equal_to<bool>(), 1, boost::bind(std::modulus<int>(), _1, 2));
    boost::function<bool(int)> unEvenLambda = boost::lambda::_1 % 2 == 1;

    count_iter fbegin(0);
    count_iter fend(10);
    // All three versions are valid
    // std::copy(boost::make_filter_iterator(unEvenSTLPred, fbegin, fend),
    // boost::make_filter_iterator(unEvenSTLPred, fend, fend),
    // std::copy(boost::make_filter_iterator(unEvenLambda, fbegin, fend),
    // boost::make_filter_iterator(unEvenLambda, fend, fend),
    std::copy(boost::make_filter_iterator<isUneven, count_iter>(fbegin, fend),
              boost::make_filter_iterator<isUneven, count_iter>(fend, fend),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    


    return 0;
}
