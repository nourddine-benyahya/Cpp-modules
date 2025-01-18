#include "ScalarConverter.hpp"

int main (int ac, char **av)
{
    if (ac == 1)
        std::cout << "invalid args" << std::endl;
    else 
    {
        for (int i = 1; i < ac ; i++)
        {
             ScalarConverter::convert(av[i]);
        }
    }
}