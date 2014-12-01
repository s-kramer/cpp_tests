#ifndef FIBOGEN_H__
#define FIBOGEN_H__
class FibonacciGenerator {
	int n;
	int x0;
	int x1;
public:
	FibonacciGenerator() : n(0) 
		{ x0 = 0; x1 = 1; }
	int operator()() {
		int newFibo;
		newFibo = x0 + x1;
		++n;
		x0 = x1;
		x1 = newFibo;
		return x0;
	}
	int count() { return n; }
};
#endif /* FIBOGEN_H__*/
