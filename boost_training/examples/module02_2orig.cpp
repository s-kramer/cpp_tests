#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
class Logger {
	private:
		std::streambuf * clogSave;
		std::ofstream ofs;
	public:
		Logger(const std::string & LogFileName) {
			clogSave = std::clog.rdbuf();
			ofs.open(LogFileName.c_str());
			std::clog.rdbuf(ofs.rdbuf());
		}
		~Logger() {
			std::clog.rdbuf(clogSave);
			ofs.close();
		}
};
int main(int argc, char * argv[]) {
	std::string LogFileName = "/tmp/log.txt";
	Logger * myLogger = new Logger(LogFileName);
	std::cout << "Test na cout.\n";
	std::clog << "Test do logu.\n";
	delete myLogger;
}
