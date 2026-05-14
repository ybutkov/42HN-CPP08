#include "easyfind.hpp"
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int toFind)
{
    typename T::iterator iter = std::find(container.begin(), container.end(), toFind);

    if (iter == container.end())
        throw std::out_of_range("easyfind: value not found");
    return iter;
}
