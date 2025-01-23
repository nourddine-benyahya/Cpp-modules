#include <iostream>
#include <vector>


std::vector<size_t> generateJacobsthal(size_t max_value) {
    std::vector<size_t> jacobsthal;
    size_t a = 0, b = 1;

    while (a <= max_value) {
        if (a != 0)
            jacobsthal.push_back(a);
        size_t next = a + 2 * b;
        a = b;
        b = next;
    }
    return jacobsthal;
}

template <typename container>
typename container::iterator binarySearch(container& vec, int target)
{
    typename container::iterator low = vec.begin();
    typename container::iterator high = vec.end();

    high--;
    while (low < high)
    {
        typename container::iterator mid = low + (high - low) / 2;
        if (*mid == target)
            return mid;
        else if (*mid < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

template <typename container>
void _sort(container &main, container &tmp)
{
    std::vector<size_t> jc = generateJacobsthal(static_cast<size_t>(tmp.size()));

    std::reverse(tmp.begin(),tmp.end());
    for (std::vector<size_t>::iterator it = jc.begin(); it != jc.end(); ++it)
    {
        typename container::iterator elem = binarySearch(main, tmp[(*it) - 1]);
        main.insert(elem, tmp[(*it) - 1]); 
    }

    size_t j = 0;
    for (typename container::iterator it = tmp.begin(); it != tmp.end(); it++)
    {
        if (j < jc.size() && *it == tmp[jc[j] - 1])
        {
            j++;
            continue;
        }
        typename container::iterator elem = binarySearch(main, *it);
        main.insert(elem, *it);
    }
}


template <typename container>
void sortingalgo(container &main)
{
    if (main.size() < 3) return;

    container other, tmp;
    size_t i = 0;

    if (main.size() == 3)
    {
        tmp.push_back(main.back());
        main.pop_back();
    }
    else
    {
        for (i = 0; i + 1 < main.size(); i += 2)
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
        }
        if (i < main.size())
            other.push_back(main[i]);
        main.swap(other); 
    }

    sortingalgo(main);
    if (main.size() == 2 && main[0] > main[1])
        std::swap(main[0], main[1]);
    _sort(main, tmp);
}
