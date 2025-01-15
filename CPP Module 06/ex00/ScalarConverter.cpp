#include "ScalarConverter.hpp"
#include <iomanip>

bool ScalarConverter::nonAnumber(const std::string data)
{
    size_t len = data.length();
    size_t i = 0;
    if (data[0] == '-' || data[0] == '+')
        i++;
    std::string number("0123456789.f");
    while (i < len && number.find(data[i++]) != std::string::npos);
    return i != len ||  (i == len && number.find(data.at(len - 1)) == std::string::npos) || (data.find("f") != data.rfind("f")) ? true : false;
}

DataType ScalarConverter::detect_type(const std::string data)
{
    if ((data.find(".") != data.rfind(".") || nonAnumber(data)) && data.length() == 1)
        return CHAR;
    else if (data.find(".") == std::string::npos && data.rfind("f") == std::string::npos && !nonAnumber(data))
        return INT;
    else if (data.find(".") == data.rfind(".") && data.at(data.length() - 1) == 'f' && !nonAnumber(data))
        return FLOAT;
    else if (data.find(".") == data.rfind(".") && !nonAnumber(data))
        return DOUBLE;
    else if (data.compare("nan") || data.compare("nanf"))
        return NAN;
    else if (data.compare("+inf") || data.compare("-inf") || data.compare("+inff") || data.compare("-inff"))
        return INF;
    else
        return ERROR;
}

int ScalarConverter::get_precision(const std::string& data)
{
    size_t dot_pos = data.find('.');
    if (dot_pos == std::string::npos)
        return 1;
    return data.length() - dot_pos - 1 - (data.at(data.length() - 1) == 'f' ? 1 : 0);
}

void print_int(long long a)
{
    std::cout << "int: ";
    a > INT_MAX || a <= INT_MIN ? std::cout <<  "impossible" : std::cout << static_cast<int>(a);
    std::cout << std::endl;
}
void print_float(long double a)
{
    std::cout << "float: ";
    a > FLT_MAX || a <= FLT_MIN ? std::cout <<  "impossible" : std::cout << static_cast<float>(a) << "f" ;
    std::cout << std::endl;
}

void print_double(long double a)
{
    std::cout << "float: ";
    a > DBL_MAX || a <= DBL_MIN ? std::cout <<  "impossible" : std::cout << static_cast<double>(a) ;
    std::cout << std::endl;
}

void ScalarConverter::print_it(long long a)
{
    (a >= 33 && a <= 126) ?
    std::cout << "char: " << static_cast<char>(a) << std::endl : std::cout << "char: " <<  "Non displayable" << std::endl ;
    print_int(a);
    std::cout << std::fixed << std::showpoint << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(a) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(a) << std::endl;
}

void ScalarConverter::print_it(float a, int precision)
{
    (a >= 33 && a <= 126) ?
    std::cout << "char: " << static_cast<char>(a) << std::endl : std::cout << "char: " <<  "Non displayable" << std::endl ;
    print_int(a);
    std::cout << std::fixed << std::showpoint << std::setprecision(precision);
    std::cout << "float: " << a << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(a) << std::endl;
}

void ScalarConverter::print_it(double a, int precision)
{
    (a >= 33 && a <= 126) ?
    std::cout << "char: " << static_cast<char>(a) << std::endl : std::cout << "char: " <<  "Non displayable" << std::endl ;
    print_int(a);
    std::cout << std::fixed << std::showpoint << std::setprecision(precision);
    std::cout << "float: " << static_cast<float>(a) << "f" << std::endl;
    std::cout << "double: " << a << std::endl;
}

void ScalarConverter::print_it(const std::string data)
{
    bool sign = false;
    bool nan = false;
    data == "nan" ? nan = true : data[0] == '-' ? sign = false : sign = true;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: ";
    nan ? std::cout << "nanf" : sign ? std::cout << "inff" : std::cout << "-inff";
    std::cout << std::endl;
    std::cout << "double: ";
    nan ? std::cout << "nan" : sign ? std::cout << "inf" : std::cout << "-inf";
    std::cout << std::endl;

}

void ScalarConverter::convert(const std::string data)
{
    long long b;
    long double d;
    float f;
    char a;
    int precision = get_precision(data);
    switch (detect_type(data))
    {
        case CHAR :
            a = data[0] ;
            print_it(static_cast<long long>(a));
            break;
        case INT :
            b = atoll(data.c_str());
            print_it(b);
            break;
        case FLOAT :
            f = static_cast<float>(atof(data.c_str()));
            print_it(f, precision);
            break;
        case DOUBLE :
            d = atof(data.c_str()) ;
            print_it(d, precision);
            break;
        case NAN :
            print_it(data);
            break;
        case INF :
            print_it(data);
            break;
        default:
            std::cout << "err :" << data << " is not valide data" << std::endl; break;
    }
}