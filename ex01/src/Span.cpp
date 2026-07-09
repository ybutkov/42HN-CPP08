#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>


Span::Span(unsigned int n): N(n) { 
    this->data.reserve(this->N);
};

Span::Span(const Span& other)
{
    this->N = other.N;
    this->data = other.data;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->N = other.N;
        this->data = other.data;
    }
    return *this;
}

const std::vector<int>& Span::getData() const
{
    return this->data;
}

void Span::addNumber(int newValue)
{
    if (this->data.size() >= this->N)
        throw SpanSizeOutException();
    data.push_back(newValue);
}

unsigned int Span::shortestSpan() const
{
    if (this->data.size() < 2)
        throw SpanCalculationException();

    std::vector<int> sorted = this->data;
    std::sort(sorted.begin(), sorted.end());
    unsigned int minDiff = static_cast<long>(sorted[1]) - sorted[0];

    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        unsigned int diff = static_cast<long>(sorted[i + 1]) - sorted[i];

        if (diff < minDiff)
            minDiff = diff;
    }
    return minDiff;
}

unsigned int Span::longestSpan() const
{
    if (this->data.size() < 2)
        throw SpanCalculationException();

    auto min = std::min_element(this->data.begin(), this->data.end());
    auto max = std::max_element(this->data.begin(), this->data.end());
    
    return static_cast<long>(*max) - *min;
}

std::ostream& operator<<(std::ostream& os, const Span& span)
{
    for (std::vector<int>::const_iterator it = span.getData().begin();
            it != span.getData().end();
            ++it)
        os << *it << ' ';
    return os;
}
