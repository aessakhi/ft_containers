/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:19:22 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/17 18:19:43 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/set.hpp"
#include "../include/utility.hpp"

using namespace ft;

int main()
{
	std::cout << "TEST SET" << std::endl;
	set<int> first; //Empty constructor;

	int ints[] = {0, 10, 20, 30, 40, 40}; //Done on purpose to check if it adds a repeated unique item, should not happen
	set<int> second(ints, ints+6); //Construct with range

	set<int> third(second.begin(), second.end()); //Construct with iterator;

	set<int> fourth;
	fourth = second;

	std::cout << std::endl;
	std::cout << "Content of second:";
	for (set<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "Content of third: ";
	for (set<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "Content of fourth: ";
	for (set<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "TESTING CAPACITY" << std::endl;
	std::cout << std::boolalpha;
	std::cout << std::endl;
	std::cout << "Test empty" << std::endl;
	std::cout << "Is first empty? " << first.empty() << std::endl;
	std::cout << "Is second empty? " << second.empty() << std::endl;
	std::cout << "Is third empty? " << third.empty() << std::endl;
	std::cout << "Is fourth empty? " << fourth.empty() << std::endl;
	std::cout << std::endl;

	std::cout << "Test size" << std::endl;
	std::cout << "Size of first: " << first.size() << std::endl;
	std::cout << "Size of second: " << second.size() << std::endl;
	std::cout << "Size of third: " << third.size() << std::endl;
	std::cout << "Size of fourth: " << fourth.size() << std::endl;

	std::cout << std::endl;
	std::cout << "Test max size" << std::endl;
	std::cout << "max_size of first: " << first.max_size() << std::endl;
	std::cout << "max_size of second: " << second.max_size() << std::endl;
	std::cout << "max_size of third: " << third.max_size() << std::endl;
	std::cout << "max_size of fourth: " << fourth.max_size() << std::endl;

	std::cout << std::endl;
	std::cout << "Test Insert" << std::endl;
	std::cout << "Inserting 11, 21, 31 and 41 in first (pair<iterator, bool> insert(const value_type& val))" << std::endl;
	first.insert(11);
	first.insert(21);
	first.insert(31);
	first.insert(41);
	std::cout << "Content of first after insert:";
	for (set<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	
	std::cout << "Inserting 15, 25, 35 in first (template <class InputInterator> void insert(InputIterator first, InputIterator last))" << std::endl;
	int ints2[] = {15, 25, 35};
	first.insert(ints2, ints2 + 3);
	std::cout << "Content of first after insert:";
	for (set<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Testing Erase" << std::endl;
	std::cout << "Erasing third element (void erase (iterator position))" << std::endl;
	set<int>::iterator it_test;
	it_test = first.begin();
	it_test++;
	it_test++;
	first.erase(it_test);
	std::cout << "Content of first after erase:";
	for (set<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Erasing 31 from first, returning the number of nodes deleted (size_type erase(const value_type& val))" << std::endl;
	std::cout << "Node(s) erased: " << first.erase(35) << std::endl;
	std::cout << "Content of first after erase:";
	for (set<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Erasing a range (void erase(iterator first, iterator last))" << std::endl;
	it_test = first.begin();
	it_test++;
	it_test++;
	first.erase(it_test, first.end());
	std::cout << "Content of first after erase:";
	for (set<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Testing swap" << std::endl;
	std::cout << "Swapping first and second" << std::endl;
	first.swap(second);
	std::cout << "Content of second:";
	for (set<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "Content of first:";
	for (set<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Testing clear" << std::endl;
	second.clear();
	std::cout << "second size is empty after clear? " << second.empty() << std::endl;

	std::cout << std::endl;
	std::cout << "Testing find" << std::endl;
	it_test = first.find(30);
	std::cout << "The iterator assigned after first.find(30) points to " << *it_test << std::endl;
	it_test = first.find(78);
	std::cout << "it_test should point to first.end() after first.find(78) (value doesn't exist): " << (it_test == first.end()) << std::endl;

	std::cout << std::endl;
	std::cout << "Testing count" << std::endl;
	std::cout << "Number of time value 20 is in first: " << first.count(20) << std::endl;
	std::cout << "Number of time value 45 is in first: " << first.count(45) << std::endl;
	std::cout << std::endl;

	std::cout << "Testing lower bound and upper bound" << std::endl;
	it_test = first.lower_bound(20);
	std::cout << "first.lower_bound(20) points to " << *it_test << std::endl;
	it_test = first.upper_bound(30);
	std::cout << "first.upper_bound(30) points to " << *it_test << std::endl;
	it_test = first.upper_bound(40);
	std::cout << "first.upper_bound(40) should point to first.end(): " << (it_test == first.end()) << std::endl;

	std::cout << std::endl;
	std::cout << "Testing equal range" << std::endl;
	pair<set<int>::const_iterator, set<int>::const_iterator> result;
	result = first.equal_range(20);
	std::cout << "Lower bound points to: " << *result.first << std::endl;
	std::cout << "Upper bound points to: " << *result.second << std::endl;

	std::cout << std::endl;
	std::cout << "TEST RELATIONAL OPERATORS" << std::endl;
	std::cout << "first different than second? " << (first != second) << std::endl;
	std::cout << "third equal to fourth? " << (third == fourth) << std::endl;
	std::cout << "first superior to second? " << (first > second) << std::endl;
	std::cout << "first inferior to second? " << (first < second) << std::endl;
	std::cout << "first superior or equal to second? " << (first >= second) << std::endl;
	std::cout << "first inferior or equal to second? " << (first <= second) << std::endl;

	std::cout << std::endl;
	std::cout << "Testing with different value_type" << std::endl;

	set<std::string> set_string;

	set_string.insert("This");
	set_string.insert("is");
	set_string.insert("a");
	set_string.insert("test");

	std::cout << "Content of set_string:";
	for (set<std::string>::iterator it = set_string.begin(); it != set_string.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
}
