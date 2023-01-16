/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_reverse_iterator.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:26:59 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/16 18:49:05 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int main()
{
	std::vector<int> test_vector;
	for (int i = 0; i < 10; i++)
		test_vector.push_back(i);
	
	typedef std::vector<int>::iterator vector_iterator;

	vector_iterator start(test_vector.begin());
	vector_iterator finish(test_vector.end());

	reverse_iterator<vector_iterator> rev_finish(start);
	reverse_iterator<vector_iterator> rev_start(finish);

	reverse_iterator<vector_iterator> rev_test = rev_start;

	std::cout << "Printing vector using reverse iterator and increment" << std::endl;
	while (rev_test != rev_finish)
		std::cout << ' ' << *rev_test++;
	std::cout << std::endl;

	std::cout << "Printing vector using reverse iterator and decrement" << std::endl;
	while (rev_test != rev_start)
		std::cout << ' ' << *(--rev_test);
	std::cout << std::endl;

	reverse_iterator<vector_iterator> rev_iterator;

	rev_iterator = test_vector.rbegin() + 3;
	std::cout << "test_vector.rbegin() + 3 points to " << *rev_iterator << std::endl;

	rev_iterator = test_vector.rbegin();
	rev_iterator += 3;
	std::cout << "rev_iterator += 3 point to " << *rev_iterator << std::endl;

	rev_iterator = test_vector.rend() - 3;
	std::cout << "test_vector.rend() - 3 points to " << *rev_iterator << std::endl;

	rev_iterator = test_vector.rend();
	rev_iterator -= 3;
	std::cout << "rev_iterator -= 3 point to " << *rev_iterator << std::endl;

	rev_iterator = test_vector.rend();
	std::cout << "rev_iterator[5] points to " << rev_iterator[5] << std::endl;

	std::cout << "Test ->" << std::endl;

	std::map<int, std::string> numbers;
	numbers.insert(std::make_pair(1, "one"));
	numbers.insert(std::make_pair(2, "two"));
	numbers.insert(std::make_pair(3, "three"));

	typedef std::map<int, std::string>::iterator map_iterator;

	reverse_iterator<map_iterator> rev_map_finish(numbers.begin());
	reverse_iterator<map_iterator> rev_map_start(numbers.end());

	for (; rev_map_start != rev_map_finish; ++rev_map_start)
		std::cout << rev_map_start->first << ' ' << rev_map_start->second << std::endl;

	return (0);
}
