#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <float.h>
#include <cmath>

enum DataType {CHAR, INT, FLOAT, DOUBLE, NANE, INF, ERROR};

class ScalarConverter 
{
    private :
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &obj);
        ScalarConverter &operator=(const ScalarConverter &obj);
        static bool nonAnumber(const std::string data);
        static DataType detect_type(const std::string data);
        static void print_int(long long a);
        static void print_float_double(long double a);
        static void print_num(long double a);
        static void print_nan_int(const std::string data);
    public :
        static void convert(const std::string data);
};