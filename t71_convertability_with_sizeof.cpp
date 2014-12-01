#include <iostream>

class Base {};
class Derived : public Base {};

typedef char Small;
class Big {
    Big(void) { (void)tmp; }
    char tmp[2];
};

Small TestConv(Base);
Big TestConv(...);

template <typename T> T makeT();

template <typename T> bool isConvertableToBase() {
    return sizeof(TestConv(makeT<T>())) == sizeof(Small);
}

template <typename T, typename U> class CovertabilityTester {
    typedef char Small;
    class Big {
        char tmp[2];
    };

    // These functions need to be static as the enum type must be known at compile time.
    static T makeT();

    static Small testConv(U);
    static Big testConv(...);

  public:
    enum isConvertable { result = sizeof(testConv(makeT())) == sizeof(Small) };
};

int main() {
    std::cout << std::boolalpha;
    std::cout << "Is Derived convertible to Base? : " << isConvertableToBase<Derived>()
              << '\n';
    std::cout << "Is int convertible to Base? : " << isConvertableToBase<int>() << '\n';

    std::cout << "Is Derived convertible to Base? (Class approach) : "
              << CovertabilityTester<Derived, Base>::result << '\n';
    std::cout << "Is int convertible to Base? (Class approach) : "
              << CovertabilityTester<Derived, int>::result << '\n';

    std::cout << "Is int convertible to float? (Class approach) : "
              << CovertabilityTester<int, float>::result << '\n';

    std::cout << "Is float convertible to int? (Class approach) : "
              << CovertabilityTester<float, int>::result << '\n';

    return 0;
}
