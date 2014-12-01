#include <iostream>

template<class Derived>
bool operator==(const Derived& lhs, const Derived& rhs)
{
    std::cout << "Operator ==\n";
    return !(lhs < rhs) && !(rhs < lhs);
}

class Class_with_less
{
public:
    explicit Class_with_less (const int in_value) : value(in_value) {};
    virtual ~Class_with_less () {};
    
    bool operator<(const Class_with_less& rhs) const;
private:
    int value;
};

bool Class_with_less::operator< (const Class_with_less& rhs) const 
{
    return value < rhs.value;
}

int main()
{
    Class_with_less c1(5), c2(10);
    std::cout << (c1 < c2) << ", " << (c2 < c1) << '\n';
    std::cout << (c1 == c2) << '\n';
    return 0;
}
