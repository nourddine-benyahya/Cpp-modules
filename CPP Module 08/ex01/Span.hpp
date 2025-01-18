#pragma once
#include <iostream>
#include <vector>
#include <exception>
#include <cmath>


class Span 
{
    private :
        std::vector<int> numbers;
        unsigned int maxSize;
    public :
        Span();
        Span(unsigned int N);
        Span(const Span &obj);
        Span &operator=(const Span &obj);
        ~Span();

        void addNumber(int a);
        int shortestSpan();
        int longestSpan();
        void rango(std::vector<int>::iterator start, std::vector<int>::iterator end);


        class fullException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };

        class emptyException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};