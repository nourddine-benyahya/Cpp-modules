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
    else if (data.find(".") == data.rfind(".") && !nonAnumber(data) && data.rfind("f") == std::string::npos)
        return DOUBLE;
    else if (!data.compare("nan") || !data.compare("nanf"))
        return NANE;
    else if (!data.compare("+inf") || !data.compare("-inf") || !data.compare("+inff") || !data.compare("-inff") || !data.compare("inf") || !data.compare("inff"))
        return INF;
    else
        return ERROR;
}

void ScalarConverter::print_int(long long a)
{
    std::cout << "int: ";
    a > INT_MAX || a <= INT_MIN ? std::cout <<  "impossible" : std::cout << static_cast<int>(a);
    std::cout << std::endl;
}
void ScalarConverter::print_float_double(long double a)
{
    std::cout << "float: " << static_cast<float>(a) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(a) << std::endl;
}


void ScalarConverter::print_num(long double a)
{
    (a >= 33 && a <= 126) ?
    std::cout << "char: " << static_cast<char>(a) << std::endl : std::cout << "char: " <<  "Non displayable" << std::endl ;
    print_int(a);
    round(a) - a == 0.0 && std::cout << std::fixed << std::showpoint << std::setprecision(1);
    print_float_double(a);
}


void ScalarConverter::print_nan_int(const std::string data)
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
    if (!data[0])
    {
        std::cout << "err : data is empty" << std::endl;
        return ;
    }
    DataType type = detect_type(data);
    if (type == CHAR)
        print_num(static_cast<long double>(data[0]));
    else if (type == INT)
        print_num(atoll(data.c_str()));
    else if (type == FLOAT || type == DOUBLE)
        print_num(static_cast<long double>(atof(data.c_str())));
    else if (type == INF || type == NANE)
        print_nan_int(data);
    else 
        std::cout << "err :" << data << " is not valide data" << std::endl;
}