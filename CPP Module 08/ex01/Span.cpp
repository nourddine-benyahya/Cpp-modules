#include "Span.hpp"

Span::Span() : maxSize(0) {};
Span::~Span(){};

Span::Span(unsigned int N) : maxSize(N){};
Span::Span(const Span &obj)
{
    maxSize = obj.maxSize;
    numbers = obj.numbers;
}

Span &Span::operator=(const Span &obj)
{
    if (this != &obj)
    {
        maxSize = obj.maxSize;
        numbers = obj.numbers;
    }
    return *this;
}

void Span::addNumber(int a)
{
    if (numbers.size() >= maxSize)
        throw fullException();
    try
    {
        numbers.push_back(a);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}

int Span::longestSpan(void)
{
    if (maxSize < 2 || numbers.size() < 2 )
        throw emptyException();
    return (*std::max_element(numbers.begin(), numbers.end()) - *std::min_element(numbers.begin(), numbers.end()));
}

int Span::shortestSpan()
{
    if (maxSize < 2 || numbers.size() < 2 )
        throw emptyException();
    std::vector<int> tmp(numbers);
    std::sort(tmp.begin(), tmp.end());

    std::vector<int>::iterator it;
    int span = abs(tmp.at(0) - tmp.at(1));

    for (it = tmp.begin(); it != tmp.end() - 1; it++)
    {
        if (abs(*it - *(it + 1)) < span)
            span = abs(*it - *(it + 1));
    }
    return (span);
}

void Span::rango(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    if (std::distance(start, end) + numbers.size() > maxSize)
        throw fullException();
    numbers.insert(numbers.end(), start, end);
}

const char * Span::fullException::what() const throw()
{
    return "u are reach the limit!!!";
} 

const char * Span::emptyException::what() const throw()
{
    return "the container is empty";
}
