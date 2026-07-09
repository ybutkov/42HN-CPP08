/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 20:53:14 by ybutkov           #+#    #+#             */
/*   Updated: 2026/07/09 15:04:42 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"
#include <iostream>

namespace {
	void testAddNumberOne()
	{
		std::cout << "+++ testAddNumberOne +++" << std::endl;
		Span sp = Span(5);
		sp.addNumber(2);
		sp.addNumber(8);
		sp.addNumber(3);
		sp.addNumber(42);
		sp.addNumber(7);
		std::cout << sp << "\n" << std::endl;
	}

	void testAddNumberOneException()
	{
		std::cout << "+++ testAddNumberOneException +++" << std::endl;
		Span sp = Span(5);
		try {
			sp.addNumber(2);
			sp.addNumber(8);
			sp.addNumber(3);
			sp.addNumber(42);
			sp.addNumber(7);
			sp.addNumber(342);
		} 
		catch (const SpanSizeOutException& ex) {
			std:: cout << "Error: " << ex.what() << std::endl;
		}
		std::cout << sp << "\n" << std::endl;
	}

	void testShortestSpanAndLongestSpan()
	{
		std::cout << "+++ testShortestSpanAndLongestSpan +++" << std::endl;
		Span sp = Span(5);
		sp.addNumber(2);
		sp.addNumber(8);
		sp.addNumber(3);
		sp.addNumber(42);
		sp.addNumber(7);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << "\n" << std::endl;	
	}

	void testAddNumberRange()
	{
		std::cout << "+++ testAddNumberRange +++" << std::endl;
		// int sizeSpan = 100;
		// int sizeRange = 20;
		int sizeSpan = 10000;
		int sizeRange = 50;
		Span sp = Span(sizeSpan);
		std::vector<int> toAddValues;
		for (int i = 1; i <= sizeRange; i++)
			toAddValues.push_back(i);
		
		for (int i = 1; i <= sizeSpan / sizeRange; i++)
		{
			sp.addNumber(toAddValues.begin(), toAddValues.end());	
		}
	
		std::cout << sp << "\n" << std::endl;	
	}

	void testShortestSpanAndLongestSpanException()
	{
		std::cout << "+++ testShortestSpanAndLongestSpanException +++" << std::endl;
		Span sp = Span(5);
		sp.addNumber(2);
		std::cout << "span: " << sp << std::endl;
		try {
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (const SpanCalculationException& ex) {
			std:: cout << "Error: " << ex.what() << std::endl;
		}
	
		try {
			std::cout << sp.longestSpan() << std::endl;		
		}
		catch (const SpanCalculationException& ex) {
			std:: cout << "Error: " << ex.what() << std::endl;
		}
	}
}

int main()
{
	testAddNumberOne();
	testAddNumberOneException();
	testShortestSpanAndLongestSpan();
	testAddNumberRange();
	testShortestSpanAndLongestSpanException();
	
	return 0;
}
