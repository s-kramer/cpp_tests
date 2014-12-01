#include <iostream>

template <typename T>
class Base
{
public:
    explicit Base (void) {};
    void Fun() { std::cout << " Base<T>::Fun() " << '\n'; }
};

template <>
void Base<char>::Fun()
{
    std::cout << "Base<char>::Fun()" << '\n';
}

template <typename T, typename U>
class OtherBase
{
public:
    explicit OtherBase (void) {};
    void Fun(void) { std::cout << "OtherBase<T>::Fun()" << '\n'; }
};

template <typename U>
void OtherBase<char, U>::Fun()
{
    std::cout << "OtherBase<char, U>::Fun()" << '\n';
}
