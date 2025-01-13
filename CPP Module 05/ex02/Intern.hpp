#pragma once

#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

class AForm;

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm makePresidentialPardonForm(const std::string& target);
        AForm makeRobotomyRequestForm(const std::string& target);
        AForm makeShrubberyCreationForm(const std::string& target);

        AForm* makeForm(const std::string& formName, const std::string& target);
};