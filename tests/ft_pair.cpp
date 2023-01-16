/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:19:55 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/16 21:21:32 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/utility.hpp"

using namespace ft;

int main()
{
	pair<int, std::string> racer1;
	pair<int, std::string> racer2(2, "Dap");
	pair<int, std::string> racer3(racer2);

	racer1 = make_pair(1 , "Per");

	std::cout << "Testing equality" << std::endl;
	if (racer2 == racer3)
		std::cout << "All good" << std::endl;
	else
		std::cerr << "Problem here" << std::endl;

	std::cout << std::endl;

	std::cout << "Testing inequality" << std::endl;
	if (racer1 != racer3)
		std::cout << "All good" << std::endl;
	else
		std::cerr << "Problem here" << std::endl;

	std::cout << "Testing <" << std::endl;
	if (racer1 < racer3)
		std::cout << "All good" << std::endl;
	else
		std::cerr << "Problem here" << std::endl;

	std::cout << "Testing >" << std::endl;
	if (racer3 > racer1)
		std::cout << "All good" << std::endl;
	else
		std::cerr << "Problem here" << std::endl;

	std::cout << "The Racer 2 is " << racer2.second << " at position " << racer2.first << std::endl;
}
