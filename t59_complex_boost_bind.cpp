#include <iostream>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/mem_fn.hpp>
#include <boost/ref.hpp>
#include <vector>

class Value
{
public:
    Value (int value) : value(value) {};
    int getValue(void) const { return value; }
    // preincrement
    Value& operator++(void) { ++value; return *this; }
    //postincrement
    Value operator++(int)
    {
        Value result(*this);
        ++(*this);
        return result;
    }
private:
    int value;
};

class Foo
{
public:
    explicit Foo (const Value& value, int scale) : value(value), scale(scale) {};
    
    Value getSpecificValue(void) { return static_cast<const Foo*>(this)->getSpecificValue(); }
    Value getSpecificValue(void) const { return value; }
    int getScale(void) const { return scale; }

private:
    Value value;
    int scale;
};

int main()
{
    using namespace boost;

    std::vector<Foo> fooVec;
    fooVec.push_back(Foo(1, 1));
    fooVec.push_back(Foo(2, 2));
    fooVec.push_back(Foo(3, 3));

    int expectedValue = 2;
    int expectedScale = 2;
    // standard version
    // boost::function<bool (const Foo&)> isValueEqual = bind(&Value::getValue, bind(&Foo::getSpecificValue, _1)) == expectedValue;
    // unambiguous version
    // 1.
    // Value (Foo::*getSpecific) () const = &Foo::getSpecificValue;
    // boost::function<bool (const Foo&)> isValueEqual = bind(&Value::getValue, bind(getSpecific, _1)) == expectedValue;
    // 2.
    boost::function<bool (const Foo&)> isValueEqual = bind(&Value::getValue, boost::bind( static_cast< Value (Foo::*) () const >( &Foo::getSpecificValue ), _1 )) == expectedValue;

    boost::function<bool (const Foo&)> isScaleEqual = bind(&Foo::getScale, _1) == expectedScale;
    boost::function<bool (const Foo&)> pred = bind(isValueEqual, _1) && bind(isScaleEqual, _1);
    boost::function<bool (const Foo&)> pred2 = bind(std::logical_and<bool>(), bind(isValueEqual, _1), bind(isScaleEqual, _1));

    fooVec.erase(std::remove_if(fooVec.begin(), fooVec.end(), pred2), fooVec.end());

    for(std::vector<Foo>::const_iterator it = fooVec.begin(); it != fooVec.end(); ++it)
    {
        std::cout << it->getSpecificValue().getValue() << " " << it->getScale() << '\n';
    }

    return 0;
}
