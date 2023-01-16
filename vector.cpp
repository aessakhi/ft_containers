/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:26:31 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/03 17:49:26 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"

int main()
{
	std::cout << "STD CONSTRUCTORS" << std::endl;
	std::vector<int> first;
	std::vector<int> second (4, 100);

	std::cout << "Content of std vector:";
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << std::endl;
	std::cout << "Vector size: ";
	std::cout << second.size() << std::endl;
	std::cout << "Vector capacity: ";
	std::cout << second.capacity() << std::endl;
	std::cout << "Vector max_size: ";
	std::cout << second.max_size() << std::endl;

	std::cout << std::endl;

	std::cout <<"FT CONSTRUCTORS" << std::endl;
	ft::vector<int> ft_first;
	ft::vector<int> ft_second (4, 100);
	std::cout << "Content of ft vector:";
	ft::vector<int>::iterator ft_it = ft_second.begin();
	for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
		std::cout << ' ' << *ft_it;

	std::cout << std::endl;
	std::cout << "ft vector size: ";
	std::cout << ft_second.size() << std::endl;
	std::cout << "ft vector capacity: ";
	std::cout << ft_second.capacity() << std::endl;
	std::cout << "ft vector max_size: ";
	std::cout << ft_second.max_size() << std::endl;

	std::cout << "Copy constructor ft::vector" << std::endl;
	ft::vector<int> ft_copy(ft_second);

	std::cout << "Copy content:";
	for (ft::vector<int>::iterator ft_copy_it = ft_copy.begin(); ft_copy_it != ft_copy.end(); ++ft_copy_it)
		std::cout << ' ' << *ft_copy_it;

	std::cout << std::endl;

	std::cout << "Checking if changing the values of the original doesn't affect the copy" << std::endl;

	for (ft::vector<int>::iterator ft_copy_it = ft_copy.begin(); ft_copy_it != ft_copy.end(); ++ft_copy_it)
		*ft_copy_it = 12;

	std::cout << "Changed all values in the copy to 12: ";
	for (ft::vector<int>::iterator ft_copy_it = ft_copy.begin(); ft_copy_it != ft_copy.end(); ++ft_copy_it)
		std::cout << ' ' << *ft_copy_it;

	std::cout << std::endl;

	std::cout << "Content of the original:";
	for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
		std::cout << ' ' << *ft_it;

	std::cout << std::endl;

	/* 	std::cout << "Test const iterator" << std::endl;
	std::vector<int>::const_iterator const_it = second.begin();
	ft::vector<int>::const_iterator ft_const_it = ft_second.begin();
	*const_it = 3;
	*ft_const_it = 3; */

	std::cout << "Test Front" << std::endl;
	std::cout << ft_second.front() << std::endl;
	std::cout << second.front() << std::endl;

	std::cout << "Test back" << std::endl;
	std::cout << ft_second.back() << std::endl;
	std::cout << second.back() << std::endl;

	std::cout << "Test []" << std::endl;
	std::cout << ft_second[1] << std::endl;
	std::cout << second[1] << std::endl;

	std::cout << "Test at" << std::endl;
	std::cout << "Test at out of range" << std::endl;
	try
	{
		std::cout << ft_second.at(6) << std::endl;
		std::cout << second.at(6) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Test at in range" << std::endl;
	std::cout << ft_second.at(2) << std::endl;
	std::cout << second.at(2) << std::endl;
	std::cout << std::endl;

	std::cout << "Test pop back" << std::endl;

	int i = 0;
	for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
		*ft_it = *ft_it + (++i);

	i = 0;
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		*it = *it + (++i);

	std::cout << "std vector before pop back:";
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "ft vector before pop back:";
	for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;

	second.pop_back();
	ft_second.pop_back();

	std::cout << "std vector after pop back:";
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	
	std::cout << "ft vector after pop back:";
	for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;

	std::cout << ft_second.max_size() << std::endl;

	std::cout << "Test Reserve" << std::endl;

	second.reserve(10);
	std::cout << "std vector after reserve:";
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "std capacity after reserve: ";
	std::cout << second.capacity() << std::endl;

	ft_second.reserve(10);
	std::cout << "ft vector after reserve:";
	for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;
	std::cout << "ft vector capacity after reserve: ";
	std::cout << ft_second.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "Test assign" << std::endl;

	second.assign(15, 3);
	ft_second.assign(15, 3);
	std::cout << "std vector after assign:";
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "std vector capacity after assign: " << second.capacity() << std::endl;
	std::cout << "ft vector after assign:";
	for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;
	std::cout << "ft vector capacity after assign: " << ft_second.capacity() << std::endl;

	i = 0;
	for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
		*ft_it = *ft_it + (++i);

	i = 0;
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		*it = *it + (++i);
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;

	std::cout << "Test Erase" << std::endl;
	std::cout << *second.erase(second.begin() + 9) << std::endl;
	std::cout << std::endl;
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << *ft_second.erase(ft_second.begin() + 9) << std::endl;
	std::cout << std::endl;
	for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;
	std::cout << second.size() << std::endl;
	std::cout << second.capacity() << std::endl;
	std::cout << ft_second.size() << std::endl;
	std::cout << ft_second.capacity() << std::endl;

	std::cout << "Test Insert" << std::endl;
	second.insert(second.begin() + 2, 15, 32);
	std::cout << second.capacity() << std::endl;
	ft_second.insert(ft_second.begin() + 2, 15, 32);
	std::cout << ft_second.capacity() << std::endl;
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;

	std::cout << *(second.insert(second.begin() + 2, 3)) << std::endl;
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << *(ft_second.insert(ft_second.begin() + 2, 3)) << std::endl;
	for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;

	std::cout << "Test push back" << std::endl;
	second.push_back(10);
	ft_second.push_back(10);
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;
	std::cout << second.capacity() << std::endl;
	std::cout << ft_second.capacity() << std::endl;
	std::cout << second.size() << std::endl;
	std::cout << ft_second.size() << std::endl;

	std::cout << "Test resize" << std::endl;
	second.resize(10);
	ft_second.resize(10);
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;
	second.resize(20, 3);
	ft_second.resize(20, 3);
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;
	second.resize(20);
	ft_second.resize(20);
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;

/* 	second.swap(first);
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	for (std::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	ft_second.swap(ft_copy); */

	std::vector<int>::iterator std_insert = second.begin();
	std::vector<int>::iterator std_insert_2 = second.end();
	second.insert(second.begin() + 5, std_insert, std_insert_2);
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	ft::vector<int>::iterator ft_insert = ft_second.begin();
	ft::vector<int>::iterator ft_insert_2 = ft_second.end();
	ft_second.insert(ft_second.begin() + 5, ft_insert, ft_insert_2);
	for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;

/* 	ft::vector<int> ft_third (10, 5);
	std::vector<int> third (10, 5);
	for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	for (ft::vector<int>::iterator ft_it = ft_third.begin(); ft_it != ft_third.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;
	std::vector<int>::iterator std_insert_1 = third.begin();
	std::vector<int>::iterator std_insert_1_2 = third.end();
	ft::vector<int>::iterator ft_insert_1 = ft_third.begin();
	ft::vector<int>::iterator ft_insert_1_2 = ft_third.end();
	std::cout << third.capacity() << std::endl;
	third.insert(third.begin() + 3, std_insert, std_insert_2);
	ft_third.insert(ft_third.begin() + 3, ft_insert, ft_insert_2);
	for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << third.capacity() << std::endl;
	for (ft::vector<int>::iterator ft_it = ft_third.begin(); ft_it != ft_third.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;
	std::cout << ft_third.capacity() << std::endl; */

/* 	ft::vector<int> ft_third(std_insert, std_insert_2);
	std::vector<int> third(std_insert, std_insert_2);
	for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	for (ft::vector<int>::iterator ft_it = ft_third.begin(); ft_it != ft_third.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl; */

	std_insert = second.begin();
	std_insert_2 = second.end();
	ft_insert = ft_second.begin();
	ft_insert_2 = ft_second.end();
	
	ft::vector<int> ft_assign(10,5);
	std::vector<int> assign(10,5);
	for (std::vector<int>::iterator it = assign.begin(); it != assign.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	for (ft::vector<int>::iterator ft_it = ft_assign.begin(); ft_it != ft_assign.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl; 

	ft_assign.assign(ft_insert, ft_insert_2);
	assign.assign(std_insert, std_insert_2);
	for (std::vector<int>::iterator it = assign.begin(); it != assign.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	for (ft::vector<int>::iterator ft_it = ft_assign.begin(); ft_it != ft_assign.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;

	std_insert = assign.begin();
	std_insert_2 = assign.end() - 5;
	ft_insert = ft_assign.begin();
	ft_insert_2 = ft_assign.end() - 5;
	assign.erase(std_insert, std_insert_2);
	ft_assign.erase(ft_insert, ft_insert_2);
	for (std::vector<int>::iterator it = assign.begin(); it != assign.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	for (ft::vector<int>::iterator ft_it = ft_assign.begin(); ft_it != ft_assign.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;

	/* ft_assign = ft_second;
	assign = second;
	for (std::vector<int>::iterator it = assign.begin(); it != assign.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	for (ft::vector<int>::iterator ft_it = ft_assign.begin(); ft_it != ft_assign.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl; */

/* 	ft_assign.swap(ft_second);
	assign.swap(second); */
	for (std::vector<int>::iterator it = assign.begin(); it != assign.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	for (ft::vector<int>::iterator ft_it = ft_assign.begin(); ft_it != ft_assign.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;

	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	for (ft::vector<int>::iterator ft_it = ft_second.begin(); ft_it != ft_second.end(); ++ft_it)
		std::cout << ' ' << *ft_it;
	std::cout << std::endl;
}
