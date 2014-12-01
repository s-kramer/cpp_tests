#include <stdint.h>

template <class T1, class T2, bool Q>
class ChoiceType
{
public:
    typedef T1 type;
};

template <class T1, class T2>
class ChoiceType<T1, T2, true>
{
public:
    typedef T2 type;
};

template <int I>
struct CounterType {
    static const bool decision = I > 255;
    typedef typename ChoiceType<uint8_t, uint16_t, decision>::type type;
};

template<unsigned MAX>
struct CounterMPL {
    typedef typename CounterType<MAX>::type type;

    CounterMPL(void) : actual(0) {}
    CounterMPL& operator++() { ++actual %= MAX; return *this; }
    type getValue(void) {return actual; }
private:
    type actual;
};
