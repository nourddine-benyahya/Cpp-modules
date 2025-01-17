#include "Iter.hpp"


int main( void ) {
    int a[]= {1,2,3,4,5,6,7,8,9,10};
    std::string s[] = {"test1", "test2", "test3"};

    iter(a, 10, func<int>);
    iter(s, 3, func<std::string>);
}