#include <iostream>
#include <vector>
#include <algorithm>
struct AverSum {
	double _sum;
	int _count;
	AverSum() : _sum(0.0), _count(0) {}
	void operator() (int n) {
		_count++;
		_sum += n;
	}
	double average() const {
		return (_sum / _count);
	}
};
int main(int argc, char* argv[]) {
	int dane[] = { 2, 6, 7, 3, 5, 8 };
	std::vector<int> v(dane, dane+6);
	AverSum a = std::for_each(v.begin(), v.end(), AverSum());
	std::cout << "Srednia z danych to: " << a.average() << "\n";
}
