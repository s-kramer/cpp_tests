#include <iostream>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits.hpp>

template <typename T>
typename boost::enable_if<boost::is_const<T>, T>::type Foo(T& t)
{
    std::cout << "Foo const T version" << '\n';
    return t;
}

template <typename T>
typename boost::enable_if<boost::is_function<T>, bool>::type Foo(T& t)
{
    std::cout << "Foo function version" << '\n';
    return t;
}

template <typename T, 
    typename boost::enable_if<boost::is_pointer<T>, int>::type = 0 >
bool Foo(T&)
{
    std::cout << "Foo pointer version" << '\n';
    return true;
}

bool isEven(int rhs) { return rhs % 2 != 0; }

int main()
{
    const int ci = 15;
    const int* cip = &ci;
    
    Foo(ci);
    Foo(isEven);
    Foo(cip);
    return 0;
}
