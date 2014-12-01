#include <iostream>
#include <string>
#include <boost/regex.hpp>
int main(int argc, char* argv[]) {
	boost::regex myRegex("(\\()|(\\))");
	boost::smatch m;
	std::string line;
	std::cout << "Podaj ci�g znak�w z nawiasami ( i ): ";
	std::cin >> line;
	int openBrace = 0; int closeBrace = 0;
	std::string::const_iterator start = line.begin();
	std::string::const_iterator end = line.end();
	while(boost::regex_search(start, end, m, myRegex)) {
		m[1].matched ? ++openBrace : ++closeBrace;
		start = m[0].second;
	}
	if ( openBrace > closeBrace) {
			std::cout << "Zbyt wiele otwar�.\n";
	} else if (closeBrace > openBrace) {
			std::cout << "Zbyt wiele zamkni��.\n";
	} else {
			std::cout << "Wszystko ok.\n";
	}
}
