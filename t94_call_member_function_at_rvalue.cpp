#include <iostream>

class Foo
{
public:
    explicit Foo (int i) {};
    void bar(void) { std::cout << "Foo::bar" << '\n'; }
};

int main()
{
    Foo(5).bar();
    return 0;
}
