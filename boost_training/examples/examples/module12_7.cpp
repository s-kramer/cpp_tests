#include <iostream>
#include <string>
#include <boost/regex.hpp>
int main(int argc, char* argv[]) {
	std::string line;
	boost::smatch m;
	boost::regex myRegex("(\\d\\d-\\d{3})|(koniec)");
	while (true) {
		std::cout << "Podaj kod pocztowy lub s³owo 'koniec': ";
		std::cin >> line;
		boost::regex_search(line, m, myRegex);
		if (m[1].matched) {
			std::cout << "Poda³e¶ kod pocztowy.\n";
		} else if (m[2].matched) {
			std::cout << "Poda³e¶ s³owo 'koniec'.\n";
			break;
		} 
	} 
}
