#include "FileReadException.hpp"
FileReadException::FileReadException(const std::string & fileIn) throw()
	: FileException(fileIn) {
	mMsg = "FileReadException: " + fileIn + ".";
}
FileReadException::FileReadException(const FileReadException & e) throw()
	: FileException(e) {
}
FileReadException & FileReadException::operator=(const FileReadException & e) throw() {
	mMsg = e.what();
	mFile = e.getFileName();
	return *this;
}
FileReadException::~FileReadException() throw() {
}
