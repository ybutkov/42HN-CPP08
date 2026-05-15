/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:00:57 by ybutkov           #+#    #+#             */
/*   Updated: 2026/05/15 16:46:32 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "easyfind.hpp"
#include <deque>
#include <list>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
void testEasyFind(T& container, int value)
{
	std::cout << "Search " << value << std::endl; 
	try
	{
		auto iter = easyfind(container, value);
		std::cout << "found " << value << " at " << *iter << std::endl;
	}
	catch (const std::exception& error)
	{
		std::cout << "Error: " << error.what() << std::endl;
	}
}

int main()
{
	std::vector<int> vector1 = {3, 6, 8, 11};
	std::list<int> list1 = {1, 2, 3, 4, 5};
	std::deque<int> deque1 = {10, 20, 30, 40};

	testEasyFind(vector1, 8);
	testEasyFind(list1, 4);
	testEasyFind(deque1, 15);
	testEasyFind(vector1, 18);

	return 0;
}
