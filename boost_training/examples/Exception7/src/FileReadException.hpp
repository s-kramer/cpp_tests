#ifndef FILEREADEXCEPTION_HPP_
#define FILEREADEXCEPTION_HPP_

#include "FileException.hpp"

class FileReadException: public FileException {
public:
	FileReadException(const FileReadException &) throw();
	explicit FileReadException(const std::string &) throw();
	FileReadException & operator=(const FileReadException &) throw();
	virtual ~FileReadException() throw();
};

#endif /* FILEREADEXCEPTION_HPP_ */
