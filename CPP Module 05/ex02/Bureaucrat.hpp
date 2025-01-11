#pragma once
#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
    const std::string name;
    int grade;

public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& obj);
    Bureaucrat& operator=(const Bureaucrat& obj);

    int getGrade() const;
    const std::string& getName() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(AForm &form);

    class GradeTooHighException : public std::exception
    {
        public:
            const char* what(void) const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char* what(void) const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);
