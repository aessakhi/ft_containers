/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_iterator_traits.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:46:59 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/16 18:14:52 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <iostream>
#include <iterator>

using namespace std;

class iterator_test: public iterator<input_iterator_tag, int>{};

int main()
{
	std::cout << "Test iterator traits" << std::endl;
	std::cout << std::endl;

	typedef iterator_traits<iterator_test> test;

	if ((typeid(test::iterator_category)) == typeid(iterator_test::iterator_category))
		std::cout << "iterator_test::iterator_category == iterator_traits<iterator_test>::iterator_category" << std::endl;
	else
		std::cerr << "Should match with iterator traits" << std::endl;

	if ((typeid(test::value_type)) == typeid(iterator_test::value_type))
		std::cout << "iterator_test::value_type == iterator_traits<iterator_test>::value_type" << std::endl;
	else
		std::cerr << "Should match with iterator traits" << std::endl;

	if ((typeid(test::pointer)) == typeid(iterator_test::pointer))
		std::cout << "iterator_test::pointer == iterator_traits<iterator_test>::pointer" << std::endl;
	else
		std::cerr << "Should match with iterator traits" << std::endl;

	if ((typeid(test::reference)) == typeid(iterator_test::reference))
		std::cout << "iterator_test::reference == iterator_traits<iterator_test>::reference" << std::endl;
	else
		std::cerr << "Should match with iterator traits" << std::endl;

	if ((typeid(test::difference_type)) == typeid(iterator_test::difference_type))
		std::cout << "iterator_test::difference_type == iterator_traits<iterator_test>::difference_type" << std::endl;
	else
		std::cerr << "Should match with iterator traits" << std::endl;

	std::cout << std::endl;
	typedef iterator_traits<int*> test_ptr;
	std::cout << "Test iterator_traits<int*>" << std::endl;

	if ((typeid(test_ptr::iterator_category)) == typeid(random_access_iterator_tag))
		std::cout << "test_ptr::iterator_category == random_access_iterator_tag" << std::endl;
	else
		std::cerr << "Should match with iterator traits" << std::endl;

	if ((typeid(test_ptr::value_type)) == typeid(int))
		std::cout << "test_ptr::value_type == int" << std::endl;
	else
		std::cerr << "Should match with iterator traits" << std::endl;

	if ((typeid(test_ptr::pointer)) == typeid(int*))
		std::cout << "test_ptr::pointer == int*" << std::endl;
	else
		std::cerr << "Should match with iterator traits" << std::endl;

	if ((typeid(test_ptr::reference)) == typeid(int&))
		std::cout << "test_ptr::reference == int&" << std::endl;
	else
		std::cerr << "Should match with iterator traits" << std::endl;

	if ((typeid(test_ptr::difference_type)) == typeid(std::ptrdiff_t))
		std::cout << "test_ptr::difference_type == std::ptrdiff_t" << std::endl;
	else
		std::cerr << "Should match with iterator traits" << std::endl;

	std::cout << std::endl;
	typedef iterator_traits<const int*> test_const_ptr;

	if ((typeid(test_const_ptr::iterator_category)) == typeid(random_access_iterator_tag))
		std::cout << "test_const_ptr::iterator_category == random_access_iterator_tag" << std::endl;
	else
		std::cerr << "Should match with iterator traits" << std::endl;

	if ((typeid(test_const_ptr::value_type)) == typeid(int))
		std::cout << "test_const_ptr::value_type == int" << std::endl;
	else
		std::cerr << "Should match with iterator traits" << std::endl;

	if ((typeid(test_const_ptr::pointer)) == typeid(const int*))
		std::cout << "test_const_ptr::pointer == int*" << std::endl;
	else
		std::cerr << "Should match with iterator traits" << std::endl;

	if ((typeid(test_const_ptr::reference)) == typeid(const int&))
		std::cout << "test_const_ptr::reference == int&" << std::endl;
	else
		std::cerr << "Should match with iterator traits" << std::endl;

	if ((typeid(test_const_ptr::difference_type)) == typeid(std::ptrdiff_t))
		std::cout << "test_const_ptr::difference_type == std::ptrdiff_t" << std::endl;
	else
		std::cerr << "Should match with iterator traits" << std::endl;
}
