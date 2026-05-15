/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybutkov <ybutkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 20:53:14 by ybutkov           #+#    #+#             */
/*   Updated: 2026/05/15 22:21:55 by ybutkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MutantStack.hpp"
#include <iostream>
#include <stack>

namespace {
	
	void testMutantStackFromSubject()
	{
		std::cout << "=== testMutantStackFromSubject ===" << std::endl;
		MutantStack<int> mstack;
		// std::stack<int>  mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Last element=" << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Current size=" << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl << std::endl;
		
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		++rit;
		--rit;
		while (rit != rite)
		{
			std::cout << *rit << " ";
			++rit;
		}
		std::cout << std::endl;
		
		std::stack<int> s(mstack);
		while (s.size())
		{
			std::cout << s.top() << " ";
			s.pop();
		}
		std::cout << std::endl << std::endl;
	}

	void testMutantStackCopyAndAssign()
	{
		std::cout << "=== testMutantStackCopyAndAssign ===" << std::endl;
		MutantStack<double> original;
		original.push(10.42);
		original.push(20.33);
		original.push(30.007);

		MutantStack<double> copied(original);
		MutantStack<double> assigned;
		assigned = original;

		std::cout << "copied top: " << copied.top() << std::endl;
		std::cout << "assigned top: " << assigned.top() << std::endl;
		std::cout << "copied size: " << copied.size() << std::endl;
		std::cout << "assigned size: " << assigned.size() << std::endl << std::endl;
	}

	void testMutantStackConstAndReverseIterators()
	{
		std::cout << "=== testMutantStackConstAndReverseIterators ===" << std::endl;
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);

		const MutantStack<int> constStack(mstack);
		MutantStack<int>::const_iterator it = constStack.begin();
		MutantStack<int>::const_iterator ite = constStack.end();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		MutantStack<int>::const_reverse_iterator rit = constStack.rbegin();
		MutantStack<int>::const_reverse_iterator rite = constStack.rend();
		while (rit != rite)
		{
			std::cout << *rit << " ";
			++rit;
		}
		std::cout << std::endl;
	}
}

int main()
{
	testMutantStackFromSubject();
	testMutantStackCopyAndAssign();
	testMutantStackConstAndReverseIterators();
	
	return 0;
}
