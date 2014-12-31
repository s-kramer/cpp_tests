#include <stdint.h>

template<int I>
struct Int2Type {
	enum { value = I };
};

template<int I, bool Choice> 
class Counter_imp {
	uint16_t count;
public:
	typedef uint16_t type;
	Counter_imp();
	Counter_imp& operator++();
	uint16_t get_value();
};

template<int I>
class Counter_imp<I, false> {
	uint8_t count;
public:
	typedef uint8_t type;
	Counter_imp();
	Counter_imp& operator++();
	uint8_t get_value();
};


template<int I, bool Choice>
Counter_imp<I, Choice>::Counter_imp() : count(0) {}

template<int I>
Counter_imp<I, false>::Counter_imp() : count(0) {}

template<int I, bool Choice>
Counter_imp<I, Choice>& Counter_imp<I, Choice>::operator++() {
	count++;
	count %= Int2Type<I>::value;
	return *this;
}

template<int I>
Counter_imp<I, false>& Counter_imp<I, false>::operator++() {
	count++;
	count %= Int2Type<I>::value;
	return *this;
}

template<int I, bool Choice>
uint16_t Counter_imp<I, Choice>::get_value() {
	return count;
}

template<int I>
uint8_t Counter_imp<I, false>::get_value() {
	return count;
}

template<int V>
struct Calculate {
	static const bool value = V > 255; 
};

template<int MAX>
class Counter {
	typedef Counter_imp<MAX, Calculate<MAX>::value> impl;
	impl myImpl;
public:
	typedef typename impl::type type;
	Counter();
	Counter& operator++();
	type get_value();
};


template<int MAX>
Counter<MAX>::Counter() : myImpl() {}

template<int MAX>
Counter<MAX>& Counter<MAX>::operator++() {
	++myImpl;
	return *this;
}

template<int MAX>
typename Counter<MAX>::type Counter<MAX>::get_value() {
	return myImpl.get_value();
}
