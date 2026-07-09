#pragma once

#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
        typedef typename Container::reverse_iterator reverse_iterator;
        typedef typename Container::const_reverse_iterator const_reverse_iterator;

        MutantStack() = default;
        MutantStack(const MutantStack& other) = default;
        MutantStack& operator=(const MutantStack& other) = default;
        ~MutantStack() = default;

        iterator begin();
        const_iterator begin() const;
        const_iterator cbegin() const noexcept;

        iterator end();
        const_iterator end() const;
        const_iterator cend() const noexcept;

        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        const_reverse_iterator crbegin() const noexcept;

        reverse_iterator rend();
        const_reverse_iterator rend() const;
        const_reverse_iterator crend() const noexcept;

};

#include "MutantStack.tpp"