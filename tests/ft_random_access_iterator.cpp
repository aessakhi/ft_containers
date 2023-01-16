/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_access_iterator.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:23:21 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/16 20:40:42 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <utility>
#include "../include/RandomAccessIterator.hpp"

using namespace ft;

int main()
{
	std::cout << "Test: RandomAccessIterator" << std::endl;

	std::vector<int> vector_test;

	for (int i = 0; i < 10; i++)
		vector_test.push_back(i);

	std::vector<int>::iterator init_start(vector_test.begin());
	std::vector<int>::iterator init_finish(vector_test.end());

	RandomAccessIterator<int> start(init_start.base());
	RandomAccessIterator<int> finish(init_finish.base());

	std::cout << "Test copy constructible" << std::endl;

	std::cout << "Start should point to vector_test.begin(): " << *start << std::endl;

	std::cout << "Test copy assignable" << std::endl;
	RandomAccessIterator<int> cpy_start(start);
	std::cout << "Cpy start should point to vector_test.begin(): " << *cpy_start << std::endl;

	std::cout << "Test incrementation" << std::endl;
	while (cpy_start != finish)
		std::cout << ' ' << *cpy_start++;
	std::cout << std::endl;

	std::cout << "Test decrementation" << std::endl;
	while (cpy_start != start)
		std::cout << ' ' << *(--cpy_start);
	std::cout << std::endl;

	std::cout << "Offset dereference operator (testing cpy_start[3]): " << cpy_start[3] << std::endl;

	cpy_start = cpy_start + 3;
	std::cout << "Testing cpy_start + 3 (arithmetic operators): " << *cpy_start << std::endl;

	cpy_start = cpy_start - 2;
	std::cout << "Testing cpy_start - 2: " << *cpy_start << std::endl;

	cpy_start += 3;
	std::cout << "Testing compound assignment cpy_start += 3: " << *cpy_start << std::endl;

	cpy_start -= 1;
	std::cout << "Testing compound assignment cpy_start -= 1: " << *cpy_start << std::endl;

	std::cout << "Testing inequality" << std::endl;
	if (cpy_start != start)
		std::cout << "Cpy start is different than start" << std::endl;
	else
		std::cerr << "Problem here" << std::endl;

	std::cout << "Testing inequality" << std::endl;
	if (cpy_start > start)
		std::cout << "Cpy start is superior to start" << std::endl;
	else
		std::cerr << "Problem here" << std::endl;

	cpy_start = start;
	std::cout << "Testing equality" << std::endl;
	if (cpy_start == start)
		std::cout << "Cpy start is equal to start" << std::endl;
	else
		std::cerr << "Problem here" << std::endl;

	std::vector<std::pair<int, std::string> > dereference_test;

	dereference_test.push_back(std::make_pair(1, "one"));
	dereference_test.push_back(std::make_pair(2, "two"));
	dereference_test.push_back(std::make_pair(3, "three"));

	typedef std::vector<std::pair<int, std::string> >::iterator iterator_deref;

	iterator_deref deref_test(dereference_test.begin());

	std::cout << "Dereference test" << std::endl;

	std::cout << deref_test->second << std::endl;

}
