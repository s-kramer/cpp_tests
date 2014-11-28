#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/construct.hpp>
#include <boost/lambda/bind.hpp>
#include <vector>
#include <algorithm>
#include <boost/iterator/counting_iterator.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/range/algorithm.hpp>

class Base
{
public:
    explicit Base(int i) { std::cout << i << '\n'; }

private:
};

int main()
{
    using namespace boost;
    using namespace boost::lambda;

    std::vector<int> numbers(boost::counting_iterator<int>(0), boost::counting_iterator<int>(10));

    std::vector<Base> b;
    b.reserve(10);
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(b), bind<Base>(lambda::constructor<Base>(), boost::lambda::_1));

    // std::vector<Base*> bp;
    // bp.reserve(10);
    // std::transform(numbers.begin(), numbers.end(), std::back_inserter(bp), bind<Base*>(lambda::new_ptr<Base>(), lambda::_1));

    // boost::for_each(bp, bind<void>(lambda::destructor(), lambda::_1));

    // This doesn't work because the pointer returned from the second bind is a
    // temporary and the first bind (constructor?) takes a non-const reference
    // to it. How to dynamically allocate memory and create smart_ptr?
    std::vector< boost::shared_ptr<Base> > bsp;
    bsp.reserve(10);
    std::transform(boost::counting_iterator<int>(0),
                   boost::counting_iterator<int>(10), std::back_inserter(bsp),
                   bind<boost::shared_ptr<Base> >(
                       lambda::constructor<shared_ptr<Base> >(),
                       bind<Base *>(lambda::new_ptr<Base>(), lambda::_1)));

    return 0;
}
