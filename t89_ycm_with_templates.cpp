#include <iostream>
#include <vector>

template <typename T>
class Foo
{
public:
    template <typename U>
    explicit Foo (U&& param) : some_parameter(std::forward<T>(param)){};
    T Bar(void); 

    struct bar
    {
        int x = 10;
        std::vector<int> numbers;
    } b;
    
private:
    T some_parameter;
};

template <typename T>
T Foo<T>::Bar(void)
{
    // This completes just fine.
    b.x;
    // This doesn't complete at all (nested template here)
    b.numbers.at(0);
    return some_parameter;
}

int main()
{
    Foo<short> f(5);

    return 0;
}
