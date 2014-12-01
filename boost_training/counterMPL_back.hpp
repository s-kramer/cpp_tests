#include <stdint.h>

template <class T1, class T2, bool Q>
class ChoiceType
{
public:
    typedef T1 type;
};

template <class T1, class T2>
class ChoiceType<T1, T2, false>
{
public:
    typedef T2 type;
};

template <int I>
struct CounterType {
    static const bool decision = I > 255;
    typedef typename ChoiceType<uint8_t, uint16_t, decision>::type type;
};

template <unsigned I>
struct Int2Type {
    enum {value = I};
};

template <int I, bool Q>
class Counter_impl
{
public:
    typedef typename CounterType::type type;
    explicit Counter_impl ();
    Counter_impl& operator++(void);
    type getValue(void);
private:
    type count;
};

template <int I>
class Counter_impl<I, false>
{
public:
    explicit Counter_impl ();
    Counter_impl& operator++(void);
    uint8_t getValue(void);
    // typedef uint8_t type;
private:
    uint8_t count;
};

template <int I, bool Q>
Counter_impl<I, Q>::Counter_impl(void) : count(0) {};

template <int I>
Counter_impl<I, false>::Counter_impl(void) : count(0) {};

template <int I, bool Q>
Counter_impl<I, Q> &Counter_impl<I, Q>::operator++(void) {
    ++count;
    count %= Int2Type<I>::value;
    return *this;
}

template <int I>
Counter_impl<I, false> &Counter_impl<I, false>::operator++(void) {
    ++count;
    count %= Int2Type<I>::value;
    return *this;
}

template<int I, bool Q>
uint16_t Counter_impl<I, Q>::getValue(void) { return count; }

template<int I>
uint8_t Counter_impl<I, false>::getValue(void) { return count; }

template <int V>
struct Calculcate {
    static const bool value = V > 255;
};

template<unsigned MAX>
struct CounterMPL {
    typedef Counter_impl<MAX, Calculcate<MAX>::value > impl;
    typedef typename impl::type type;

    CounterMPL(void);
    CounterMPL& operator++();
    type getValue(void);
private:
    impl myImpl;
};

template<unsigned MAX>
CounterMPL<MAX>::CounterMPL() {}

template<unsigned MAX>
CounterMPL<MAX>& CounterMPL<MAX>::operator++(void)
{
    ++myImpl();
    return *this;
}

template<unsigned MAX>
typename CounterMPL<MAX>::type CounterMPL<MAX>::getValue(void)
{
    return myImpl.getValue();
}

