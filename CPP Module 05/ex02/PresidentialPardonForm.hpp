#pragma once

#include <string>
#include "Bureaucrat.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
    private :
        const std::string target;
    public :
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const &executor) const;
};