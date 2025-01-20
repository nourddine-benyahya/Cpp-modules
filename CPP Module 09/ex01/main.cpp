#include "RPN.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
        std::cerr << "invalid args" << std::endl;
    else
    {
        try
        {
            RPN(av[1]);
        }
        catch (const char *s){
            std::cout << s << std::endl;
        }
    }
}