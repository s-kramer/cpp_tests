#include <iostream>
#include <exception>

class myException : public std::exception {
	virtual const char * what() const throw()
	{
		return "Przynajmniej wyj±tek jest mój!";
	}
} myexception;

int main( int argc, char * argv[]) {
	try {
		throw myexception;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}
