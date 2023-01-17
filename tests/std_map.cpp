/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_map.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:34:19 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/17 19:13:22 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main()
{
	std::cout << "Test map" << std::endl;
	
	map<char, int> first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 40;
	first['d'] = 50;

	map<char, int> second(first.begin(), first.end()); //Constructor with iterator
	map<char, int> third(second);
	map<char, int> fourth;
	map<char, int> fifth;

	fourth = first;

	std::cout << "Content of first" << std::endl;
	for (map<char,int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << it->first << " => " << it->second << ' ';
	std::cout << std::endl;

	std::cout << "Content of second" << std::endl;
	for (map<char,int>::iterator it=second.begin(); it!=second.end(); ++it)
		std::cout << it->first << " => " << it->second << ' ';
	std::cout << std::endl;

	std::cout << "Content of third" << std::endl;
	for (map<char,int>::iterator it=third.begin(); it!=third.end(); ++it)
		std::cout << it->first << " => " << it->second << ' ';
	std::cout << std::endl;

	std::cout << "Content of fourth" << std::endl;
	for (map<char,int>::iterator it=fourth.begin(); it!=fourth.end(); ++it)
		std::cout << it->first << " => " << it->second << ' ';
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Test capacity" << std::endl;
	std::cout << "Test empty" << std::endl;
	std::cout << std::boolalpha;
	std::cout << "Is first empty? " << first.empty() << std::endl;
	std::cout << "Is second empty? " << second.empty() << std::endl;
	std::cout << "Is third empty? " << third.empty() << std::endl;
	std::cout << "Is fourth empty? " << fourth.empty() << std::endl;
	std::cout << "Is fifth empty? " << fifth.empty() << std::endl;
	std::cout << std::endl;

	std::cout << "Test size" << std::endl;
	std::cout << "size of first: " << first.size() << std::endl;
	std::cout << "size of fifth: " << fifth.size() << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Test max_size" << std::endl;
	std::cout << "max_size of first: " << first.max_size() << std::endl;
	std::cout << "max_size of fifth: " << fifth.max_size() << std::endl;

	std::cout << "Test insert" << std::endl;
	std::cout << "Testing pair<iterator, bool> insert(const value_type &val)" << std::endl;
	first.insert(pair<char, int>('f', 300));
	std::cout << "Content of first after first.insert(pair<char, int>('f', 300))" << std::endl;
	for (map<char,int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << it->first << " => " << it->second << ' ';
	std::cout << std::endl;
	std::cout << "Size of first after insert: " << first.size() << std::endl;
	std::cout << std::endl;
	std::cout << "Trying to insert a pair with a key which already exists" << std::endl;
	first.insert(pair<char, int>('a', 300));
	std::cout << "Content of first after first.insert(pair<char, int>('a', 300))" << std::endl;
	for (map<char,int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << it->first << " => " << it->second << ' ';
	std::cout << std::endl;
	std::cout << "Size of first after a failed insert: " << first.size() << std::endl;
	std::cout << std::endl;

	std::cout << "Range insertion" << std::endl;
	map<char, int> new_map;
	new_map.insert(first.begin(), first.find('c'));
	std::cout << "Content of new_map after fnew_map.insert(first.begin(), first.find('c'))" << std::endl;
	for (map<char,int>::iterator it=new_map.begin(); it!=new_map.end(); ++it)
		std::cout << it->first << " => " << it->second << ' ';
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Test Erase" << std::endl;
	std::cout << "Testing void erase(iterator position)" << std::endl;
	first.erase(first.find('a'));
	std::cout << "Content of first after first.erase(first.find('a'))" << std::endl;
	for (map<char,int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << it->first << " => " << it->second << ' ';
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Testing size_type erase(const key_type &k)" << std::endl;
	std::cout << "Node(s) deleted after first.erase('d'): " << first.erase('d') << std::endl;
	std::cout << "Node(s) deleted after first.erase('z'): " << first.erase('z') << std::endl;
	std::cout << std::endl;
	std::cout << "Testing void erase (iterator first, iterator last)" << std::endl;
	first.erase(first.find('c'), first.end());
	std::cout << "Content of first after first.erase(first.find('c'), first.end())" << std::endl;
	for (map<char,int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << it->first << " => " << it->second << ' ';
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Testing clear" << std::endl;
	first.clear();
	std::cout << "Is first empty after clear?: " << first.empty() << std::endl;

	std::cout << std::endl;
	std::cout << "Testing lower_bounds, upper_bounds and equal" << std::endl;
	first.insert(make_pair('a', 1));
	first.insert(make_pair('b', 2));
	first.insert(make_pair('c', 3));
	first.insert(make_pair('d', 4));
	first.insert(make_pair('e', 5));
	first.insert(make_pair('f', 6));
	std::cout << "Content of first" << std::endl;
	for (map<char,int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << it->first << " => " << it->second << ' ';
	std::cout << std::endl;
	std::cout << std::endl;

	pair<map<char, int>::iterator, map<char, int>::iterator> result;
	result = first.equal_range('c');
	std::cout << "lower bounds points to: ";
	std::cout << result.first->first << " => " << result.first->second << std::endl; 
	std::cout << "lower bounds points to: ";
	std::cout << result.second->first << " => " << result.second->second << std::endl;
}
