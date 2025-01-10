#pragma once
#include <iostream>
#include <string>

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

    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw()
        {
            return "TOO HIGH";
        };
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw()
        {
            return "TOO LOW";
        };
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);
