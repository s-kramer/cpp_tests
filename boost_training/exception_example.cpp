#include <iostream>
#include <exception>
#include <iterator>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <limits>

class FileException : public std::exception
{
public:
    explicit FileException (const char* msg) : msg(msg){};
    virtual const char* what(void) const throw()
    { 
        std::stringstream msgStream("File exception");
        msgStream << msg;
        return msgStream.str().c_str();
    }
    
protected:
    const char* msg;
};

class FileReadException : public FileException
{
public:
    explicit FileReadException (const char* msg) : FileException(msg) {};
    virtual const char* what(void) const throw()
    {
        std::string msgstr ("File read exception: ");
        msgstr+=(msg);
        return msgstr.c_str();
    }
};

class FileSyntaxException : public FileException
{
public:
    explicit FileSyntaxException (const char* msg, unsigned int line) : FileException(msg), line(line) {};
    
    virtual const char* what(void) const throw()
    {
        std::string msgstr ("File syntax exception: ");
        msgstr+=(msg);
        msgstr+=" in line ";
        std::stringstream buf;
        buf << line;
        msgstr+= buf.str();
        return msgstr.c_str();
    }

private:
    unsigned int line;
};

int main()
{
    std::cout << "Int max: " << std::numeric_limits<int>::max() << '\n';

    try {
        std::fstream infile("dane");
        if (!infile.is_open())
        {
            throw FileException("No such file");
        }

        std::string line;
        unsigned int sum = 0, index = 0, actual = 0;

        while (std::getline(infile, line))
        {
            try 
            {
                actual = std::stoi(line);
            }
            catch (std::invalid_argument& e) 
            {
                throw FileSyntaxException(e.what(), index);
            }
            catch (std::range_error& e)
            {
                throw FileSyntaxException(e.what(), index);
            }
            
            sum += actual;
            ++index;
        }

        std::cout << "Sum: " << sum << '\n';
    }
    catch (const FileSyntaxException& e) {
        std::cout << e.what() << '\n';
    }
    catch (const FileReadException& e) {
        std::cout << e.what() << '\n';
    }
    catch (const FileException& e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}
