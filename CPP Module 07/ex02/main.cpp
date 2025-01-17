#include "Array.hpp"


int main()
{
    Array<std::string> arr(5);
    try 
    {
        for (unsigned int i = 0 ; i < arr.size(); i++)
        {
            arr[i] = "hello";
        }
        arr[-15];
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try {
        for (unsigned int i = 0; i < arr.size(); i++)
        {
            std::cout << arr[i] << std::endl;
        }
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}