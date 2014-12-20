#include <iostream>
#include <boost/function.hpp>

template <typename T>
class Foo
{
  public:
    explicit Foo(boost::function<T(void)> func) : func_(func){};

  private:
    boost::function<T(void)> func_;
};

template <typename T>
class Bar
{
  public:
    explicit Bar(T bar) : bar_(bar){};

  private:
    T bar_;
};

int main()
{
    // Foo f;
    Bar b;
    return 0;
}
