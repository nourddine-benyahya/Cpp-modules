#include "ScalarConverter.hpp"

bool nonAnumber(const std::string data)
{
    size_t len = data.length();
    size_t i = 0;
    if (data[0] == '-' || data[0] == '+')
        i++;
    std::string number("0123456789.f");
    while (i < len && number.find(data[i++]) != std::string::npos);
    return i != len ||  (i == len && number.find(data.at(len - 1)) == std::string::npos) || (data.find("f") != data.rfind("f")) ? true : false;
}

DataType detect_type(const std::string data)
{
    if ((data.find(".") != data.rfind(".") || nonAnumber(data)) && data.length() == 1)
        return CHAR;
    else if (data.find(".") == std::string::npos && data.rfind("f") == std::string::npos && !nonAnumber(data))
        return INT;
    else if (data.find(".") == data.rfind(".") && data.at(data.length() - 1) == 'f' && !nonAnumber(data))
        return FLOAT;
    else if (data.find(".") == data.rfind(".") && !nonAnumber(data))
        return DOUBLE;
    return ERROR;
}


void print_it(int a)
{
    std::cout << "char: " << static_cast<char>(a) << std::endl;
    std::cout << "int: " << static_cast<int>(a) << std::endl;
    std::cout << "float: " << static_cast<float>(a) << std::endl;
    std::cout << "double: " << static_cast<double>(a) << "f" <<  std::endl;
}

void print_it(float a)
{
    std::cout << "char: " << static_cast<char>(a) << std::endl;
    std::cout << "int: " << static_cast<int>(a) << std::endl;
    std::cout << "float: " << a << std::endl;
    std::cout << "double: " << static_cast<double>(a) << "f" << std::endl;
}

void print_it(double a)
{
    std::cout << "char: " << static_cast<char>(a) << std::endl;
    std::cout << "int: " << static_cast<int>(a) << std::endl;
    std::cout << "float: " << static_cast<float>(a) << std::endl;
    std::cout << "double: " << a << "f" << std::endl;
}

void ScalarConverter::convert(const std::string data)
{
    int b;
    double d;
    float f;
    char a;
    switch (detect_type(data))
    {
        case CHAR :
            a = data[0] ;
            print_it(a);
            break;
        case INT :
            b = atoi(data.c_str()); 
            print_it(b);
            break;
        case FLOAT :
            f = static_cast<float>(atof(data.c_str()));
            print_it(f);
            break;
        case DOUBLE :
            d = atof(data.c_str()) ;
            print_it(d);
            break;
        default:
            std::cout << "err :" << data << " is not valide data" << std::endl; break;
    }
}