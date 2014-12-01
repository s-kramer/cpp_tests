#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/construct.hpp>
#include <algorithm>
#include <boost/iterator/counting_iterator.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/lambda/algorithm.hpp>
#include <boost/mem_fn.hpp>
#include <boost/ref.hpp>
#include <numeric>

class Base
{
public:
    explicit Base (int i) : i_(i) { std::cout << "Creating: " << i << std::endl; }
    ~Base(){ std::cout << "Deleting: " << i_ << std::endl; }
    int getValue(void) { return i_; }
private:
    int i_;
};

int main()
{
    using namespace boost;
    using namespace boost::lambda;

    // Create a contrainer of non-smart ptrs
    // std::vector<Base*> bp;
    // bp.reserve(10);
    // std::transform(boost::counting_iterator<int>(0), boost::counting_iterator<int>(10), std::back_inserter(bp),
            // bind<Base*>(lambda::new_ptr<Base>(), _1));

    // boost::for_each(bp, bind<void>(lambda::destructor(), _1));

    std::vector< boost::shared_ptr<Base> > bsp;
    bsp.reserve(10);

    // Create a container of smart ptrs
    std::transform(boost::counting_iterator<int>(0), boost::counting_iterator<int>(10), std::back_inserter(bsp),
            bind< boost::shared_ptr<Base> >(lambda::constructor< boost::shared_ptr<Base> >(), bind<Base*>(lambda::new_ptr<Base>(), lambda::_1)));

    // Sum all numbers
    int sum = 0;
    std::accumulate(bsp.begin(), bsp.end(), 0, (var(sum) += bind(&Base::getValue, bind(&shared_ptr<Base>::get, _2))) );
    std::cout << "Sum: " << sum << '\n';

    // Print all numbers
    std::transform(bsp.begin(), bsp.end(), std::ostream_iterator<int>(std::cout, "\n"), (std::cout << constant("Hello "), bind(&Base::getValue, bind(&shared_ptr<Base>::get, _1))));

    return 0;
}
