#pragma once

#include <string>
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
// #include <stdlib.h> 

class RobotomyRequestForm : public AForm
{
    private :
        const std::string target;
    public :
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const &executor) const;
};