#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
class tailIterator: public std::iterator<std::input_iterator_tag, std::string> {
	std::string* p;
public:
	tailIterator(std::string* s) : p(s) {}
	tailIterator(const tailIterator& iIt): p(iIt.p) {}
	tailIterator& operator++() { ++p; return *this; }
	tailIterator& operator++(int) {
		tailIterator tmpIter(*this); operator++(); return tmpIter;
	}
	bool operator==(const tailIterator& rhs) { return p == rhs.p; }
	bool operator!=(const tailIterator& rhs) { return p != rhs.p; }
	std::string& operator*() {
		std::reverse((*p).begin(), (*p).end());
		return *p;
	}
};
int main(int argc, char* argv[]) {
	std::string dane[] = { "Ala", "ma", "kotka" };
	tailIterator start(dane), end(dane+3);
	for (tailIterator it=start; it != end; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
