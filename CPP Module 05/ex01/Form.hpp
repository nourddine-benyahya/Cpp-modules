#pragma once 
#include <string>
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
    private :
     const std::string name;
     bool isSigned;
     const int gradeToSign;
     const int gradeToExecute;
    
    public :
        Form();
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat &signer);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what(void) const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what(void) const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Form& obj);