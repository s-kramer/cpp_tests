#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <boost/bind.hpp>

using namespace boost::lambda;

class A {
  int i; mutable int j;
public:

  A(int ii, int jj) : i(ii), j(jj) {};
  void set_i(int x) { i = x; }; 
  void set_j(int x) const { j = x; }; 
};

int main()
{
    A a(0,0); int k = 1;
    /* The comments privided in the library doc isn't correct. No error is present. The copy is not a const copy. */
    boost::bind(&A::set_i, a, boost::lambda::_1)(k); // error; a const copy of a is stored. 
    // Cannot call a non-const function set_i
    boost::bind(&A::set_j, a, boost::lambda::_1)(k); // a.j == 0, as a copy of a is modified

    return 0;
}
