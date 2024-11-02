
#include <iostream>
 
int add(int a,int b)
{return a +b;}

int sub(int a,int b)
{return a -b;}

int main()
{
    int (*fun[2])(int, int) = {add, sub};

    std::cout << (*fun[0])(5, 6) << std::endl;
    std::cout << (*fun[1])(5, 6) << std::endl;
}