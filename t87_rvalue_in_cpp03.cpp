#include <iostream>

class Foo
{
public:
    explicit Foo (void) {};
    Foo(Foo&& rhs)
    {
        std::cout <<  "Inside of a move ctr" << '\n'; 
    }
private:
};

int main()
{
    Foo f;

    return 0;
}
