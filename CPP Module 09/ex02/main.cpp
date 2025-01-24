#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iomanip>

bool nonAnumber(const std::string data)
{
    size_t len = data.length();
    size_t i = 0;
    if (data[0] == '+' || data[0] == '-')
        i++;
    std::string number("0123456789");
    while (i < len && number.find(data[i++]) != std::string::npos);
    return i != len || data[0] == '.' ||  (i == len && number.find(data.at(len - 1)) == std::string::npos) || (data.find("f") != data.rfind("f")) ? true : false;
}

int main(int ac, char *av[])
{
    std::vector<int> vec;
    std::deque<int> deq;
    if (ac <= 2)
    {
        std::cout << "u should enter more than one number" << std::endl;
        return 1;
    }
    for (int i = 1; i < ac; i++)
    {
        if (nonAnumber(av[i]))
        {
            std::cerr << "invalid data" << std::endl; 
            return 1;
        }
        if (atol(av[i]) > 2147483647 || atol(av[i]) <= -2147483648)
        {
            std::cerr << "out of range" << std::endl;
            return 1;
        }
        vec.push_back(atoi(av[i]));
        deq.push_back(atoi(av[i]));
    }

    std::cout << "Before: ";
    for (std::vector<int>::iterator itt = vec.begin(); itt != vec.end(); itt++)
    {
        std::cout << " " << *itt;
    }
    std::cout << std::endl;

    clock_t start_time = clock();
    sortingalgo(vec);
    clock_t end_time = clock();
    double elapsed_time_us = static_cast<double>(static_cast<double>(end_time) - static_cast<double>(start_time)) / CLOCKS_PER_SEC * 10;

    clock_t start_time1 = clock();
    sortingalgo(deq);
    clock_t end_time1 = clock();
    double elapsed_time_us1 = static_cast<double>(static_cast<double>(end_time1) - static_cast<double>(start_time1)) / CLOCKS_PER_SEC * 10;

    std::cout << "After: ";
    for (std::vector<int>::iterator itt = vec.begin(); itt != vec.end(); itt++)
    {
        std::cout << " " << *itt;
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of "<< vec.size() <<" elements with std::vector : " << elapsed_time_us << " us" << std::endl;
    std::cout << "Time to process a range of "<< deq.size() <<" elements with std::deque : "<< elapsed_time_us1 << " us" << std::endl;

}