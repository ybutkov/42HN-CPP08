#pragma once

#include <vector>
#include <stdexcept>
#include <iterator>
#include <type_traits>
#include <ostream>


class Span
{
    static constexpr unsigned int DEFAULT_AMOUNT = 16;
    unsigned int N;
    std::vector<int> data;
public:
    Span(): Span(DEFAULT_AMOUNT) {};
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span() {};

    const std::vector<int>& getData() const;

    void addNumber(int newValue);
    
    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end);

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
};


class SpanException: public std::exception { };

class SpanSizeOutException: public SpanException {
public:
	const char* what() const noexcept override { return "Size limit reached"; }
};

class SpanCalculationException: public SpanException {
public:
	const char* what() const noexcept override { return "Not enough data for calculation"; }
};

std::ostream& operator<<(std::ostream& os, const Span& span);


template <typename Iterator>
void Span::addNumber(Iterator begin, Iterator end)
{
    static_assert(
        std::is_same_v<typename std::iterator_traits<Iterator>::value_type, int>,
        "Span::addNumber requires iterators over int");

    const unsigned int amount = static_cast<unsigned int>(std::distance(begin, end));

    if (this->data.size() + amount > this->N)
        throw SpanSizeOutException();

    this->data.insert(this->data.end(), begin, end);
}
