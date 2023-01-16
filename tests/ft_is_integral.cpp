/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integral.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:47:22 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/16 17:53:53 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/type_traits.hpp"

using namespace ft;

int main()
{
	std::cout << "Test is_integral" << std::endl;
	std::cout << std::endl;
	std::cout << std::boolalpha;
	std::cout << "is_integral:" << std::endl;
	std::cout << "bool: " << is_integral<bool>::value << std::endl;
	std::cout << "char: " << is_integral<char>::value << std::endl;
	std::cout << "wchar_t: " << is_integral<wchar_t>::value << std::endl;
	std::cout << "signed char: " << is_integral<signed char>::value << std::endl;
	std::cout << "short int: " << is_integral<short int>::value << std::endl;
	std::cout << "int: " << is_integral<int>::value << std::endl;
	std::cout << "long int: " << is_integral<long int>::value << std::endl;
	std::cout << "long long int: " << is_integral<long long int>::value << std::endl;
	std::cout << "unsigned char: " << is_integral<unsigned char>::value << std::endl;
	std::cout << "unsigned short int: " << is_integral<unsigned short int>::value << std::endl;
	std::cout << "unsigned int: " << is_integral<unsigned int>::value << std::endl;
	std::cout << "unsigned long int: " << is_integral<unsigned long int>::value << std::endl;
	std::cout << "unsigned long long int: " << is_integral<unsigned long long int>::value << std::endl;
	std::cout << "float: " << is_integral<float>::value << std::endl;

	return 0;
}
