/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:42:31 by aessakhi          #+#    #+#             */
/*   Updated: 2022/12/23 22:33:26 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <iostream>
#include <map>
#include <vector>

#include "RandomAccessIterator.hpp"

int	main()
{
	std::cout << "Test: random_access_iterator" << std::endl;

	std::vector< int > myvector;
	for (int i = 0; i < 10; i++) myvector.push_back(i);

	std::vector<int>::iterator std_start(myvector.begin());
	std::vector<int>::iterator std_end(myvector.end());

	std_start++;
	std::cout << "Start = " << *std_start << std::endl;
	std::cout << "End = " << *std_end << std::endl;

	ft::RandomAccessIterator<int> ft_start(std_start.base());
	
	std::cout << "FT Start = " << *ft_start << std::endl;

	ft::RandomAccessIterator<int> ft_copy;
	std::vector<int>::iterator std_copy;

	ft_copy = ft_start;
	std_copy = std_start;

	ft_copy++;
	std_copy++;
	std::cout << "Std Copy = " << *std_copy << std::endl;
	std::cout << "FT Copy = " << *ft_copy << std::endl;

	std::cout << "FT Start = " << ft_start[4] << std::endl;

	std::cout << "FT - = " << ft_start - ft_copy << std::endl;

	std::cout << "std - = " << std_start - std_copy << std::endl;

	ft::RandomAccessIterator<int> ft_new;
	std::vector<int>::iterator std_new;

	ft_new = 2 + ft_start;
	std_new = 2 + std_start;

	std::cout << "FT + = " << *ft_new << std::endl;

	std::cout << "FT + = " << *std_new << std::endl;

}
