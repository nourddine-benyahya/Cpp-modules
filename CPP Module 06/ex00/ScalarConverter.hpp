#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <float.h>

enum DataType {CHAR, INT, FLOAT, DOUBLE, NAN, INF, ERROR};

class ScalarConverter 
{
    private :
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);
        ScalarConverter &operator=(const ScalarConverter &obj);
        static bool nonAnumber(const std::string data);
        static DataType detect_type(const std::string data);
        static int get_precision(const std::string& data);
        static void print_it(long long a);
        static void print_it(float a, int precision);
        static void print_it(double a, int precision);
        static void print_it(const std::string data);

    public :
        static void convert(const std::string data);
};