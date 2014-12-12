#include <iostream>

namespace a{
    namespace b{
        class Foo
        {
        };
    }
}

namespace e{
    namespace f{
        class Bar
        {
        };
    }
}

bool operator==(const a::b::Foo& lhs, const e::f::Bar& rhs)
{
    (void)lhs;
    (void)rhs;
    return true;
}

namespace g{
    namespace h{
        void compare(void)
        {
            a::b::Foo f;
            e::f::Bar b;
            if (f == b) 
            {
                std::cout <<  "Operator works!" << '\n';
            }
        }
    }
}

int main()
{

    g::h::compare();
    return 0;
}
