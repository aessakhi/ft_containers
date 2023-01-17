/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_speed_stack.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:49:55 by aessakhi          #+#    #+#             */
/*   Updated: 2023/01/17 19:51:27 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <sys/time.h>
#include <utility>

#define TIME_FACTOR 1000

using namespace std;

long	get_usec_from_epoch()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_usec + tv.tv_sec * TIME_FACTOR * TIME_FACTOR);
}

long	get_relative_us(struct timeval begin_tv)
{
	struct timeval	current_tv;
	long			sec_interval;
	long			usec_interval;

	gettimeofday(&current_tv, NULL);
	sec_interval = current_tv.tv_sec - begin_tv.tv_sec;
	usec_interval = current_tv.tv_usec - begin_tv.tv_usec;
	return (usec_interval + sec_interval * TIME_FACTOR * TIME_FACTOR);
}

long	get_relative_ms(struct timeval begin_tv)
{
	struct timeval	current_tv;
	long			sec_interval;
	long			usec_interval;

	gettimeofday(&current_tv, NULL);
	sec_interval = current_tv.tv_sec - begin_tv.tv_sec;
	usec_interval = current_tv.tv_usec - begin_tv.tv_usec;
	return (usec_interval / TIME_FACTOR + sec_interval * TIME_FACTOR);
}

int main()
{
	struct timeval before;
	stack<pair<int, char> > stack_test;

	size_t	n_of_insert = 5000000;

	gettimeofday(&before, NULL);
	for (size_t i = 0; i < n_of_insert; i++)
		stack_test.push(make_pair(i, 'a'));
	std::cout << "Time to insert 5000000 pair: " << get_relative_ms(before) << " ms" << std::endl;
	
	gettimeofday(&before, NULL);
	for (size_t i = 0; i < n_of_insert; i++)
		stack_test.pop();
	std::cout << "Time to pop 5000000 pair: " << get_relative_ms(before) << " ms" << std::endl;
}
