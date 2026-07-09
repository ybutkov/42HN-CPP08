/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:00:57 by ybutkov           #+#    #+#             */
/*   Updated: 2026/07/06 20:27:38 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "easyfind.hpp"
#include <deque>
#include <list>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
void testEasyFind(T& container, const std::string& nameContainer, int value)
{
	std::cout << "Search " << value << " in <" << nameContainer << ">\n"; 
	try
	{
		auto iter = easyfind(container, value);
		std::cout << "easyfind(...) found " << value 
			<< " at pos=" << std::distance(container.begin(), iter) 
			<< "\n" << std::endl;
	}
	catch (const std::exception& error)
	{
		std::cout << "Error: " << error.what() << "\n" << std::endl;
	}
}

int main()
{
	std::vector<int> vector = {3, 6, 8, 11};
	std::list<int> list = {1, 2, 3, 4, 5};
	std::deque<int> deque = {10, 20, 30, 40, 3};

	for (int target : {8, 4, 15, 18, 3})
	{
		std::cout << "====================================================" << std::endl;
    	testEasyFind(vector, "vector", target);
    	testEasyFind(list, "list", target);
    	testEasyFind(deque, "deque", target);
	}

	return 0;
}
