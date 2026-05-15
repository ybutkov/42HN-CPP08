#pragma once

#include <vector>
#include <stdexcept>
#include <iterator>
#include <type_traits>
#include <list>
#include <fstream>
#include <ostream>

class Span
{
    static constexpr unsigned int DEFAULT_AMOUNT = 16;
    unsigned int N;
    unsigned int size;
    std::vector<int> data;
public:
    Span(): Span(DEFAULT_AMOUNT) {};
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span() {};

    const std::vector<int>& getData() const;
    void addNumber(int newValue);
    
    template <typename It>
    std::enable_if_t<
        std::is_base_of<
            std::input_iterator_tag,
            typename std::iterator_traits<It>::iterator_category
        >::value
    >
    addNumber(It begin, It end);
    
    unsigned int shortestSpan();
    unsigned int longestSpan();
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

template <typename It>
std::enable_if_t<
    std::is_base_of<
        std::input_iterator_tag,
        typename std::iterator_traits<It>::iterator_category
    >::value
>
Span::addNumber(It begin, It end)
{
    const unsigned int amount = static_cast<unsigned int>(std::distance(begin, end));

    if (this->size + amount > this->N)
        throw SpanSizeOutException();

    this->data.insert(this->data.end(), begin, end);
    this->size += amount;
}