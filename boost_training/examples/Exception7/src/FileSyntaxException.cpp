#include "FileSyntaxException.hpp"
#include <sstream>

FileSyntaxException::FileSyntaxException(const std::string & fileIn, unsigned lineNumIn) throw()
	: FileException(fileIn), mLineNum(lineNumIn) {
	std::ostringstream ostr;
	ostr << "FileSyntaxError: " << fileIn << ", in line " <<
			lineNumIn;
	 mMsg = ostr.str();
}

FileSyntaxException::FileSyntaxException(const FileSyntaxException & e) throw()
		: FileException(e), mLineNum(e.mLineNum) {
}

FileSyntaxException & FileSyntaxException::operator=(const FileSyntaxException & e) throw() {
	mMsg = e.mMsg;
	mFile = e.mFile;
	mLineNum = e.mLineNum;
	return *this;
}

FileSyntaxException::~FileSyntaxException() throw() {
}

const unsigned FileSyntaxException::getLineNum() {
	return mLineNum;
}
