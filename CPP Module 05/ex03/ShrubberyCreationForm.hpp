#pragma once

#include <string>
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class ShurbberyCreationForm : public AForm
{
    private :
        const std::string target;
    public :
        ShurbberyCreationForm();
        ShurbberyCreationForm(const std::string& target);
        ShurbberyCreationForm(const ShurbberyCreationForm& other);
        ShurbberyCreationForm& operator=(const ShurbberyCreationForm& other);
        ~ShurbberyCreationForm();

        void execute(Bureaucrat const &executor) const;
};