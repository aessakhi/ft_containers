/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:31:08 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/14 18:35:43 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree.hpp"
#include <functional>

int main()
{
	ft::RBTree<int, int, std::_Identity<int>, std::less<int> > tree;
	tree.insert_unique(52);
	tree.insert_unique(32);
	tree.insert_unique(40);
	tree.insert_unique(5);
	tree.insert_unique(7);
	std::cout << tree.size() << std::endl;
	for (ft::RBTree<int, int, std::_Identity<int>, std::less<int> >::iterator it = tree.begin(); it != tree.end(); ++it)
		std::cout << *it << std::endl;
	ft::RBTree<int, int, std::_Identity<int>, std::less<int> >::iterator it_test = tree.begin();
	it_test++;
	std::cout << *it_test << std::endl;
	tree.erase(it_test);
	std::cout << std::endl;
	for (ft::RBTree<int, int, std::_Identity<int>, std::less<int> >::iterator it = tree.begin(); it != tree.end(); ++it)
		std::cout << *it << std::endl;
	ft::RBTree<int, int, std::_Identity<int>, std::less<int> >::iterator it_end = tree.end();
	--it_end;
	std::cout << std::endl;
	/* std::cout << *it_end << std::endl; */
	tree.erase(it_end);
	for (ft::RBTree<int, int, std::_Identity<int>, std::less<int> >::iterator it = tree.begin(); it != tree.end(); ++it)
		std::cout << *it << std::endl;
}
