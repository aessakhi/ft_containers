/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_algorithm.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:47:17 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/16 21:52:40 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool mypredicate (int i, int j) 
{
	return (i==j);
};

bool mycomp (char c1, char c2)
{
	return std::tolower(c1)<std::tolower(c2);
}

int main () {
	int myints[] = {20,40,60,80,100};
	std::vector<int>myvector (myints,myints+5);

	if ( equal (myvector.begin(), myvector.end(), myints) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

	myvector[3]=81;                                 // myvector: 20 40 60 81 100

	// using predicate comparison:
	if ( equal (myvector.begin(), myvector.end(), myints, mypredicate) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

	char foo[] = "Apple";
	char bar[] = "apartment";

	std::cout << std::boolalpha;

	std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

	std::cout << "Using default comparison (operator<): ";
	std::cout << lexicographical_compare(foo,foo+5,bar,bar+9); //Stop at first char since A < a
	std::cout << '\n';

	std::cout << "Using mycomp as comparison object: ";
	std::cout << lexicographical_compare(foo,foo+5,bar,bar+9,mycomp); //mycomp compares lowercase, stops at p in Apple since p > a
	std::cout << '\n';

	return 0;
}
