/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:02:58 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/16 23:33:30 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/vector.hpp"

using namespace ft;

int main()
{
	std::cout << "CONSTRUCTORS TEST" << std::endl;

	vector<int> first;
	vector<int> second(4, 100); //4 ints with value 100
	vector<int> third(second.begin(), second.end()); //Using iterators to build the vector
	vector<int> fourth(third); //Copy constructor

	std::cout << std::endl;
	std::cout << "The contents of second should be 4 ints with a value of 100:";
	for (vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "The contents of third should identical to second (constructed using iterators):";
	for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "The contents of fourth should identical to second and third (copy constructor):";
	for (vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "CAPACITY FUNCTIONS TEST" << std::endl;

	std::cout << std::endl;
	std::cout << "Vector size: ";
	std::cout << second.size() << std::endl;
	std::cout << "Vector capacity: ";
	std::cout << second.capacity() << std::endl;
	std::cout << "Vector max_size: ";
	std::cout << second.max_size() << std::endl;

	std::cout << std::endl;
	std::cout << "Changing values of third" << std::endl;
	size_t i = 0;
	for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		*it = i++;
	std::cout << "The contents of third are:";
	for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Checking if checking the values of third didn't affect second" << std::endl;
	std::cout << "The contents of second are:";
	for (vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	/*
	//WILL NOT COMPILE ON PURPOSE WITH THIS UNCOMMENTED
	std::cout << std::endl;
	std::cout << "Test const iterator" << std::endl;
	vector<int>::const_iterator const_it = second.begin();
	*const_it = 3;
	*/

	std::cout << std::endl;
	std::cout << "Test front" << std::endl;
	std::cout << third.front() << std::endl;

	std::cout << std::endl;
	std::cout << "Test back" << std::endl;
	std::cout << third.back() << std::endl;

	std::cout << std::endl;
	std::cout << "Test []" << std::endl;
	std::cout << third[1] << std::endl;

	std::cout << std::endl;
	std::cout << "Test at" << std::endl;
	std::cout << "Test at out of range" << std::endl;
	try
	{
		std::cout << third.at(6) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "Test at in range" << std::endl;
	std::cout << third.at(2) << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Test pop_back" << std::endl;
	std::cout << "The contents of third before pop_back are:";
	for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;	
	third.pop_back();
	third.pop_back();
	std::cout << std::endl;
	std::cout << "The contents of third after 2 pop_back are:";
	for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "Testing multiple pop_back in a row to empty the vector, this should NOT crash" << std::endl;
	third.pop_back();
	third.pop_back();
	third.pop_back();
	third.pop_back();
	third.pop_back();
	third.pop_back();

	std::cout << std::endl;
	std::cout << "Test void assign(size_type n, const value_type &value), here third.assign(15, 3)" << std::endl;
	third.assign(15, 3);
	std::cout << "The contents of third should be 3 repeated 15 times:";
	for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Test template <class InputIt> void assign(InputIt first, InputIt last), here second.assign(third.begin(), third.begin() + 7)" << std::endl;
	std::cout << "The contents of second before assign are:";
	for (vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	second.assign(third.begin(), third.begin() + 7);
	std::cout << std::endl;
	std::cout << "The contents of second after assign are:";
	for (vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Test resize" << std::endl;
	std::cout << "The capacity of third before resize is: " << third.capacity() << std::endl;
	third.resize(30);
	std::cout << "The capacity of third after resize is: " << third.capacity() << std::endl;

	std::cout << std::endl;
	std::cout << "Test reserve" << std::endl;
	std::cout << "Testing when the reserved size if inferior to the current capacity" << std::endl;
	std::cout << "Contents of third before reserve(10):";
	for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	third.resize(10);
	std::cout << "Contents of third after reserve(10):";
	for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Test push_back" << std::endl;
	std::cout << "Contents of third before push_back:";
	for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "Pushing back 1, 2, 3, 4, 5" << std::endl;
	i = 1;
	while (i < 6)
		third.push_back(i++);
	std::cout << "Contents of third after push_back:";
	for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Test Insert" << std::endl;
	std::cout << "Testing void insert(iterator position, size_type n, const value_type& val)" << std::endl;
	third.insert(third.begin() + 10, 5, 7);
	std::cout << "Contents of third after third.insert(third.begin() + 10, 5, 7):";
	for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Testing iterator insert(iterator position, const value_type &val)" << std::endl;
	third.insert(third.begin() + 2, 9);
	std::cout << "Contents of third after third.insert(third.begin() + 2, 9):";
	for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Testing template<class InputIt> void insert(iterator position, InputIterator first, InputIterator last)" << std::endl;
	third.insert(third.begin() + 3, fourth.begin(), fourth.end());
	std::cout << "Contents of third after third.insert(third.begin() + 3, fourth.begin(), fourth.end()):";
	for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Testing erase" << std::endl;
	std::cout << "Testing iterator erase(iterator position)" << std::endl;
	third.erase(third.begin() + 2);
	std::cout << "Contents of third after third.erase(third.begin() + 2):";
	for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "Testing iterator erase(iterator first, iterator last" << std::endl;
	third.erase(third.end() - 5, third.end());
	std::cout << "Contents of third after third.erase(third.end() - 5, third.end()):";
	for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Testing swap" << std::endl;
	third.swap(second);
	std::cout << "Contents of third after swapping with second:";
	for (vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "Contents of second after swapping with third:";
	for (vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Testing Relational operators" << std::endl;
	if (second != third)
		std::cout << "second and third are different" << std::endl;
	else
		std::cerr << "Problem here" << std::endl;
	if (second > third)
		std::cout << "second is superior to third" << std::endl;
	else
		std::cerr << "Problem here" << std::endl;
	if (third < second)
		std::cout << "third is inferior to second" << std::endl;
	else
		std::cerr << "Problem here" << std::endl;
	first = second;
	if (second == first)
		std::cout << "first and second are equal" << std::endl;
	else
		std::cerr << "Problem here" << std::endl;

	return (0);
}
