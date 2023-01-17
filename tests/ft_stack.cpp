/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:17:32 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/17 15:26:49 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/stack.hpp"
#include "../include/vector.hpp"
#include <deque>
#include <list>

using namespace ft;

int main()
{
	std::cout << "TEST STACK" << std::endl;
	std::cout << std::endl;

	std::deque<int> deque_test (5, 10);
	vector<int> vector_test (10, 7);


	stack<int, std::deque<int> > first; //Empty stack
	stack<int, std::deque<int> > second(deque_test);

	stack<int, vector<int> > third;
	stack<int, vector<int> > fourth(vector_test);

	std::cout << "TEST SIZE" << std::endl;
	std::cout << "Size of first (is empty): " << first.size() << std::endl;
	std::cout << "Size of second (should be 5): " << second.size() << std::endl;
	std::cout << "Size of third (is empty): " << third.size() << std::endl;
	std::cout << "Size of fourth (should be 10): " << fourth.size() << std::endl;

	std::cout << std::endl;
	std::cout << "TEST EMPTY" << std::endl;
	std::cout << std::boolalpha;
	std::cout << "first is empty? " << first.empty() << std::endl;
	std::cout << "second is empty? " << second.empty() << std::endl;
	std::cout << "third is empty? " << third.empty() << std::endl;
	std::cout << "fourth is empty? " << fourth.empty() << std::endl;

	std::cout << "TEST PUSH" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "Pushing " << i << " in first" << std::endl;
		first.push(i);
	}
	std::cout << "Size of first after pushing 10 elements: " << first.size() << std::endl;

	std::cout << std::endl;
	std::cout << "TEST POP" << std::endl;
	while (!first.empty())
	{
		std::cout << ' ' << first.top();
		first.pop();
	}
	std::cout << std::endl;

	std::cout << "TEST RELATIONAL OPERATORS" << std::endl;
	std::cout << "first different than second? " << (first != second) << std::endl;
	std::cout << "first equal to second? " << (first == second) << std::endl;
	std::cout << "first superior to second? " << (first > second) << std::endl;
	std::cout << "first inferior to second? " << (first < second) << std::endl;
	std::cout << "first superior or equal to second? " << (first >= second) << std::endl;
	std::cout << "first inferior or equal to second? " << (first <= second) << std::endl;

	std::cout << std::endl;
	std::cout << "TEST WITH LIST (deque and vector done)" << std::endl;

	stack<std::string, std::list<std::string> > stack_list;
	stack_list.push("test");
	stack_list.push("a");
	stack_list.push("is");
	stack_list.push("This");
	while (!stack_list.empty())
	{
		std::cout << ' ' << stack_list.top();
		stack_list.pop();
	};
	std::cout << std::endl;
}
