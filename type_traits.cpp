/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:57:18 by aessakhi          #+#    #+#             */
/*   Updated: 2022/12/27 13:19:37 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "type_traits.hpp"

int main() {
  std::cout << std::boolalpha;
/*   std::cout << "std::is_integral:" << std::endl;
  std::cout << "bool: " << std::is_integral<bool>::value << std::endl;
  std::cout << "char: " << std::is_integral<char>::value << std::endl;
  std::cout << "char16_t: " << std::is_integral<char16_t>::value << std::endl;
  std::cout << "char32_t: " << std::is_integral<char32_t>::value << std::endl;
  std::cout << "wchar_t: " << std::is_integral<wchar_t>::value << std::endl;
  std::cout << "signed char: " << std::is_integral<signed char>::value << std::endl;
  std::cout << "short int: " << std::is_integral<short int>::value << std::endl;
  std::cout << "int: " << std::is_integral<int>::value << std::endl;
  std::cout << "long int: " << std::is_integral<long int>::value << std::endl;
  std::cout << "long long int: " << std::is_integral<long long int>::value << std::endl;
  std::cout << "unsigned char: " << std::is_integral<unsigned char>::value << std::endl;
  std::cout << "unsigned short int: " << std::is_integral<unsigned short int>::value << std::endl;
  std::cout << "unsigned int: " << std::is_integral<unsigned int>::value << std::endl;
  std::cout << "unsigned long int: " << std::is_integral<unsigned long int>::value << std::endl;
  std::cout << "unsigned long long int: " << std::is_integral<unsigned long long int>::value << std::endl;
  std::cout << "float: " << std::is_integral<float>::value << std::endl; */
  std::cout << "ft::is_integral:" << std::endl;
  std::cout << "bool: " << ft::is_integral<bool>::value << std::endl;
  std::cout << "char: " << ft::is_integral<char>::value << std::endl;
/*   std::cout << "char16_t: " << ft::is_integral<char16_t>::value << std::endl;
  std::cout << "char32_t: " << ft::is_integral<char32_t>::value << std::endl; */
  std::cout << "wchar_t: " << ft::is_integral<wchar_t>::value << std::endl;
  std::cout << "signed char: " << ft::is_integral<signed char>::value << std::endl;
  std::cout << "short int: " << ft::is_integral<short int>::value << std::endl;
  std::cout << "int: " << ft::is_integral<int>::value << std::endl;
  std::cout << "long int: " << ft::is_integral<long int>::value << std::endl;
  std::cout << "long long int: " << ft::is_integral<long long int>::value << std::endl;
  std::cout << "unsigned char: " << ft::is_integral<unsigned char>::value << std::endl;
  std::cout << "unsigned short int: " << ft::is_integral<unsigned short int>::value << std::endl;
  std::cout << "unsigned int: " << ft::is_integral<unsigned int>::value << std::endl;
  std::cout << "unsigned long int: " << ft::is_integral<unsigned long int>::value << std::endl;
  std::cout << "unsigned long long int: " << ft::is_integral<unsigned long long int>::value << std::endl;
  std::cout << "float: " << ft::is_integral<float>::value << std::endl;
  return 0;
}
