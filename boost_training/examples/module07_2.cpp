#include <queue>
#include <iostream>
struct myCompare {
	bool operator() (const int& lhs, const int& rhs) const {
		return (lhs < rhs);
	}
};
int main(int argc, char* argv[]) {
	int dane[] = { 2, 42, 523, 4, 244, 32, 423, 4};
	std::priority_queue<int, std::vector<int>, myCompare> prioQueue;
	for (int i = 0; i < 8; i++)
		prioQueue.push(dane[i]);
	for (int i = 0; i < 8; i++) {
		std::cout << prioQueue.top() << "\n";
		prioQueue.pop();
	}
}
