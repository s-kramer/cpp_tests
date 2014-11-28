#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>
#include "t40_exceptions_tests.h"

class MyException : public std::exception
{
public:
    explicit MyException (unsigned errorCode, const char* exceptionMessage) : 
        exceptionMessage_ (exceptionMessage),
        errorCode_ (errorCode)
    {};

    /* Use the what() as a key into a table of error message table */
    virtual const char* what() const noexcept
    {
        return exceptionMessage_;
    }

    unsigned getErrorCode(void) const
    {
        return errorCode_;
    }

private:
    /* Don't use std::string in exception class as it may throw itself. */
    const char* exceptionMessage_;
    /* Expose relevant information in class' public interface */
    unsigned errorCode_;
};

void processAge(int studentAge)
{
    if (studentAge < 0) {
        // throw std::invalid_argument("Provided age is negative.");
        // throw "Negative age provided";
        throw MyException(5, "Negative age provided");
    }
    std::cout << "Student's age: " << studentAge << '\n';
}
 
void processGrade(int studentGrade)
{
    if (studentGrade < MIN_GRADE || studentGrade > MAX_GRADE) {
        throw "Grade out of range provided";
    }
    std::cout << "Student's grade: " << studentGrade << '\n';
}

int main()
{
    double studentAge = 0, studentGrade = 0;
    std::string studentName;
    std::cout << "Age, name, grade: \n";
    try {
    std::cin >> studentAge >> studentName >> studentGrade;
    }
    catch(...) {
        std::cout << "Provided age is not a number\n";
    }
    
    try {
        processAge(studentAge);
        processGrade(studentGrade);
    }
    catch (std::invalid_argument& e) {
        std::cout << "Exception: " << e.what() << '\n';
    }
    catch (const char* e) {
        std::cout << "Some error occured: " << e << '\n';
    }
    catch (MyException& myException)
    {
        std::cout << "Error #" << myException.getErrorCode() << ": " <<myException.what() << '\n';
    }

    return 0;
}
