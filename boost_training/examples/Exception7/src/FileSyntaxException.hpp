#ifndef FILESYNTAXEXCEPTION_HPP_
#define FILESYNTAXEXCEPTION_HPP_

#include "FileException.hpp"

class FileSyntaxException: public FileException {
public:
	FileSyntaxException(const FileSyntaxException &) throw();
	explicit FileSyntaxException(const std::string &, unsigned) throw();
	FileSyntaxException & operator=(const FileSyntaxException &) throw();
	virtual ~FileSyntaxException() throw();
	const unsigned getLineNum();
protected:
	unsigned mLineNum;
};

#endif /* FILESYNTAXEXCEPTION_HPP_ */
