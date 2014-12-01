#include "FileException.hpp"
FileException::FileException(const std::string & fileIn) throw()
	: std::runtime_error(""), mFile(fileIn) {
	mMsg = "FileException: ";
}
FileException::FileException(const FileException & e) throw()
	: std::runtime_error(e) {
	mMsg = e.mMsg;
	mFile = e.mFile;
}
FileException & FileException::operator=(const FileException & e) throw() {
	mMsg = e.mMsg;
	mFile = e.mFile;
	return *this;
}
FileException::~FileException() throw() {
}
const char * FileException::what() const throw() {
	return mMsg.c_str();
}
const std::string FileException::getFileName() const throw() {
	return mFile;
}
