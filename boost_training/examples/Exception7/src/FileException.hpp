/*
 * FileException.hpp
 *
 *  Created on: 2010-03-04
 *      Author: tojas
 */

#ifndef FILEEXCEPTION_HPP_
#define FILEEXCEPTION_HPP_

#include <string>
#include <stdexcept>

class FileException : public std::runtime_error {
public:
	FileException(const FileException &) throw ();
	explicit FileException(const std::string &) throw();
	FileException & operator=(const FileException &) throw();
	virtual ~FileException() throw();
	virtual const char * what() const throw();
	const std::string getFileName() const throw();
protected:
	std::string mFile, mMsg;
};

#endif /* FILEEXCEPTION_HPP_ */
