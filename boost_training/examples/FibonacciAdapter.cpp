#include <iostream>
#include <numeric>
#include "FiboGen.h"
class FibonacciAdapter {
	FibonacciGenerator f;
	int length;
public:
	FibonacciAdapter(int size): length(size) {}
	class iterator;
	friend class iterator;
	class iterator: public std::iterator<
		std::input_iterator_tag, FibonacciAdapter, ptrdiff_t> {
		FibonacciAdapter& ap;
	public:
		typedef int value_type;
		iterator(FibonacciAdapter& a): ap(a) {}
		bool operator==(const iterator&) const {
			return ap.f.count() == ap.length;
		}
		bool operator!=(const iterator& x) const {
			return !(*this == x);
		}
		int operator*() const { return ap.f(); }
		iterator& operator++() { return *this; }
		iterator operator++(int) { return *this; }
	};
	iterator begin() { return iterator(*this); }
	iterator end() { return iterator(*this); }
};
int main(int argc, char* argv[])
{
	const int SIZE = 10;
	FibonacciAdapter a1(SIZE);
	std::cout << "accumulate: " << std::accumulate(a1.begin(),
		a1.end(), 0) << "\n";
	FibonacciAdapter a2(SIZE), a3(SIZE);
	std::cout << "inner_product: " << std::inner_product(a2.begin(),
		a2.end(), a3.begin(), 0) << "\n";
	return 0;
}
