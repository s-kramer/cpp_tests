#include <iostream>
#include <type_traits>

/* ToDo: check what happens when we pass a const int* so both overloads are equal (skramer, Thu 02 Oct 2014 08:59:46 PM CEST) */

// Templates are gready, a reference to template will will in overload resolution almost always.
template <typename T> void foo (const T&)
{
    std::cout << "Foo reference version" << '\n';
    std::cout << "T is a pointer? " << std::is_pointer<T>::value << '\n';
    std::cout << "T is const? " << std::is_const<T>::value << '\n';
}

template <typename T> void foo (const T*)
{
    std::cout << "Foo ptr version" << '\n';
}

int main()
{
    int* ptr = nullptr;
    const int* cptr = nullptr;
    foo(ptr);
    foo(cptr);
    return 0;
}
