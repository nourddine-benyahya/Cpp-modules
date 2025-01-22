#include <iostream>

template <typename container>
void sortingalgo(container &main)
{
    container other;
    container tmp;
    size_t i = 0;
    if (main.size() < 3)
        return ;
    if (main.size() == 3)
    {
        tmp.push_back(main.back());
        main.erase(main.end());
    }
    else
    {
        while (i + 1 < main.size())
        {
            if (main[i] > main[i + 1])
            {
                other.push_back(main[i]);
                tmp.push_back(main[i + 1]);
            }
            else
            {
                other.push_back(main[i + 1]);
                tmp.push_back(main[i]);
            }
            main.erase(main.begin() + i, main.begin() + i + 2);
        }
        if (main.size() == 1)
        {
            other.push_back(main[0]);
            main.erase(main.begin());
        }
        main = other;
    }
    for (typename container::iterator it = main.begin(); it != main.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "----------------------" << std::endl;
    for (typename container::iterator it = tmp.begin(); it != tmp.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "+++++++++++++++++++++" << std::endl;
    sortingalgo(main);
}