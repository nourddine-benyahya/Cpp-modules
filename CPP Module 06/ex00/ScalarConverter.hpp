#pragma once

#include <string>
#include <iostream>

enum DataType {CHAR, INT, FLOAT, DOUBLE, ERROR};

class ScalarConverter 
{
    private :
        ScalarConverter();
    public :
        static void convert(const std::string data);
};