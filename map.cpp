/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:02:34 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/15 19:57:17 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <map>
#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace ft;


int main( void )
{
	map<int, char>				testedMap;
	map<int, char>::iterator	it, ite;

	size_t				numberOfPushes = 5000000;

	for (size_t i = 0; i < numberOfPushes; i++)
		testedMap.insert(make_pair(i, 'a'));
	it = testedMap.begin();
	ite = testedMap.end();
	while (it != ite)
	{
		it++;
	}
	testedMap.clear();
	return 0;
}
