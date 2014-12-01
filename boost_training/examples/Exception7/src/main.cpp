#include <iostream>
#include <fstream>
#include "FileException.hpp"
#include "FileReadException.hpp"
#include "FileSyntaxException.hpp"

using namespace std;

// Obliczanie sumy liczb z podanego jako argument pliku.
int sumValueInFile(const string & fileName)
	throw(FileReadException, FileSyntaxException)
{
	ifstream IF(fileName.c_str());
	if(!IF)
		throw FileReadException(fileName.c_str());

	int value, sum = 0, lineNum = 0;
	while(IF >> value) {
		lineNum++;
		sum += value;
	}
	if(IF.eof())
		return sum;
	else {
		IF.close();
		throw FileSyntaxException(fileName.c_str(), ++lineNum);
	}
}
int main(int argc, char **argv) {
	try {
		int sum;
		std::string fileName = "dane.txt";
		sum = sumValueInFile(fileName);
		cout << "Suma danych w pliku wynosi: " << sum <<
				endl;
	} catch (const FileException & e) {
		cerr << e.what() << endl;
	}
	return 0;
}
