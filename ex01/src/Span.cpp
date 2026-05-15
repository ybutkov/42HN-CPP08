#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>


Span::Span(unsigned int n): N(n), size(0) { 
    this->data.reserve(this->N);
};


Span::Span(const Span& other)
{
    this->N = other.N;
    this->size = other.size;
    this->data = other.data;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->N = other.N;
        this->size = other.size;
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
    if (this->size >= this->N)
        throw SpanSizeOutException();
    this->size++;
    data.push_back(newValue);
}

unsigned int Span::shortestSpan()
{
    if (this->size < 2)
        throw SpanCalculationException();

    std::vector<int> sorted = this->data;
    std::sort(sorted.begin(), sorted.end());
    int minDiff = std::abs(sorted[1] - sorted[0]);

    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        int diff = std::abs(sorted[i + 1] - sorted[i]);

        if (diff < minDiff)
            minDiff = diff;
    }
    return minDiff;
}

unsigned int Span::longestSpan()
{
    if (this->size < 2)
        throw new SpanCalculationException();

    auto min = std::min_element(std::begin(this->data), std::end(this->data));
    auto max = std::max_element(std::begin(this->data), std::end(this->data));
    
    return *max - *min;
}

std::ostream& operator<<(std::ostream& os, const Span& span)
{
    for (std::vector<int>::const_iterator it = span.getData().begin();
        it != span.getData().end(); ++it)
        os << *it << ' ';
    return os;
}
