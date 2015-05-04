#include <iostream>

class MyNonInheritingException
{
public:
    explicit MyNonInheritingException (  ) : i(5) {};
    void fun()
    {
        throw *this;
    }
    int i;
    
};

int main()
{
    try {
        MyNonInheritingException e;
        e.fun();
    }
    catch (MyNonInheritingException& e) {
        std::cout << e.i << '\n';
    }
    
    return 0;
}
