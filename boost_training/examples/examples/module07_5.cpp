#include <iostream>
#include <vector>
#include <numeric>
int main(int argc, char* argv[]) {
	int dane[] = { 2, 6, 7, 3, 5, 8 };
	std::vector<int> v(dane, dane+6);
	double aver = std::accumulate(v.begin(), v.end(), 0.0)/v.size();
	std::cout << "Srednia z danych to: " << aver << "\n";
}
