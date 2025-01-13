#pragma once 
#include <string>
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
    private :
     const std::string name;
     bool isSigned;
     const int gradeToSign;
     const int gradeToExecute;
    
    public :
        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();

        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat &signer);
        virtual void execute(Bureaucrat const &executor) const = 0;

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

std::ostream& operator<<(std::ostream& out, const AForm& obj);