#include <stack>
#include <deque>
#include <iostream>

template <typename T> 
class MutantStack : public std::stack<T>
{
    public :
        //define types 
        typedef typename std::deque<T>::iterator iterator;
        typedef typename std::deque<T>::const_iterator const_iterator;
        typedef typename std::deque<T>::reverse_iterator reverse_iterator;
        typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

        // iterators:
        iterator       begin() {return this->c.begin();};
        const_iterator begin() const {return this->c.begin();};
        iterator       end() {return this->c.end();};
        const_iterator end() const {return this->c.end();};

        reverse_iterator       rbegin() {return this->c.rbegin();};
        const_reverse_iterator rbegin() const {return this->c.rbegin();};
        reverse_iterator       rend() {return this->c.rend();};
        const_reverse_iterator rend() const {return this->c.rend();};

        const_iterator         cbegin() const {return this->c.cbegin();};
        const_iterator         cend() const {return this->c.cend();};
        const_reverse_iterator crbegin() const {return this->c.crbegin();};
        const_reverse_iterator crend() const {return this->c.crend();};
};