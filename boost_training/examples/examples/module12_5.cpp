#include <iostream>
#include <boost/regex.hpp>
int main(int argc, char* argv[]) {
	std::string line;
	boost::regex myRegex("\\d\\d-\\d{3}");
	std::cout << "Podaj kod pocztowy: ";
	std::cin >> line;
	if (boost::regex_match(line, myRegex)) {
		std::cout << "To jest poprawny kod pocztowy.\n";	
	} else {
		std::cout << "To nie jest poprawny kod pocztowy.\n";	
	}
}
