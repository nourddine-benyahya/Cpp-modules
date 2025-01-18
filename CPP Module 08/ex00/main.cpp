#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>
#include <iostream>

int main() {
    std::vector<int> vc;
    vc.push_back(1);
    vc.push_back(2);
    vc.push_back(3);
    vc.push_back(5);
    vc.push_back(8);
    easyfind(vc, 5);
    easyfind(vc, 99);



    std::deque<int> dq;
    dq.push_back(7);
    dq.push_back(456);
    dq.push_back(1);
    dq.push_back(13);
    dq.push_back(48);
    easyfind(dq, 1);
    easyfind(dq, 99);

    std::list<int> lst;
    lst.push_back(12);
    lst.push_back(575);
    lst.push_back(4);
    lst.push_back(4515);
    easyfind(lst, 4);
    easyfind(lst, 99);

    return 0;
}
