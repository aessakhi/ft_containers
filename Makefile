# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 20:02:48 by aessakhi          #+#    #+#              #
#    Updated: 2023/01/17 23:18:34 by aessakhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

OBJS = $(SRCS:.cpp=.o)
OBJS_VECTOR = $(SRCS_VECTOR:.cpp=.o)
OBJS_STACK = $(SRCS_STACK:.cpp=.o)
OBJS_MAP = $(SRCS_MAP:.cpp=.o)
OBJS_SET = $(SRCS_SET:.cpp=.o)
OBJS_ELSE = $(SRCS_ELSE:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp

SRCS_VECTOR = tests/ft_vector.cpp tests/std_vector.cpp tests/std_speed_vector.cpp tests/ft_speed_vector.cpp

SRCS_STACK = tests/ft_stack.cpp tests/std_stack.cpp tests/std_speed_stack.cpp tests/ft_speed_stack.cpp

SRCS_MAP = tests/ft_map.cpp tests/std_map.cpp tests/std_speed_map.cpp tests/ft_speed_map.cpp

SRCS_SET = tests/ft_set.cpp tests/std_set.cpp tests/std_speed_set.cpp tests/ft_speed_set.cpp

SRCS_ELSE = tests/ft_algorithm.cpp tests/std_algorithm.cpp \
			tests/ft_iterator_traits.cpp tests/std_iterator_traits.cpp tests/ft_pair.cpp tests/std_pair.cpp \
			tests/ft_random_access_iterator.cpp tests/std_random_access_iterator.cpp tests/ft_reverse_iterator.cpp tests/std_reverse_iterator.cpp

RM =	rm -rf

$(NAME):	$(OBJS) | vector stack set map else
			$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS)

all: $(NAME)

vector: ft_vector std_vector ft_speed_vector std_speed_vector

ft_vector:	tests/ft_vector.o
			$(CXX) -o ft_vector tests/ft_vector.o $(CXXFLAGS)

std_vector:	tests/std_vector.o
			$(CXX) -o std_vector tests/std_vector.o $(CXXFLAGS)

ft_speed_vector:	tests/ft_speed_vector.o
			$(CXX) -o ft_speed_vector tests/ft_speed_vector.o $(CXXFLAGS)

std_speed_vector:	tests/std_speed_vector.o
			$(CXX) -o std_speed_vector tests/std_speed_vector.o $(CXXFLAGS)



stack: ft_stack std_stack ft_speed_stack std_speed_stack

ft_stack:	tests/ft_stack.o
			$(CXX) -o ft_stack tests/ft_stack.o $(CXXFLAGS)

std_stack:	tests/std_stack.o
			$(CXX) -o std_stack tests/std_stack.o $(CXXFLAGS)

ft_speed_stack:	tests/ft_speed_stack.o
			$(CXX) -o ft_speed_stack tests/ft_speed_stack.o $(CXXFLAGS)

std_speed_stack:	tests/std_speed_stack.o
			$(CXX) -o std_speed_stack tests/std_speed_stack.o $(CXXFLAGS)



map: ft_map std_map ft_speed_map std_speed_map

ft_map:	tests/ft_map.o
			$(CXX) -o ft_map tests/ft_map.o $(CXXFLAGS)

std_map:	tests/std_map.o
			$(CXX) -o std_map tests/std_map.o $(CXXFLAGS)

ft_speed_map:	tests/ft_speed_map.o
			$(CXX) -o ft_speed_map tests/ft_speed_map.o $(CXXFLAGS)

std_speed_map:	tests/std_speed_map.o
			$(CXX) -o std_speed_map tests/std_speed_map.o $(CXXFLAGS)



set: ft_set std_set ft_speed_set std_speed_set

ft_set:	tests/ft_set.o
			$(CXX) -o ft_set tests/ft_set.o $(CXXFLAGS)

std_set:	tests/std_set.o
			$(CXX) -o std_set tests/std_set.o $(CXXFLAGS)

ft_speed_set:	tests/ft_speed_set.o
			$(CXX) -o ft_speed_set tests/ft_speed_set.o $(CXXFLAGS)

std_speed_set:	tests/std_speed_set.o
			$(CXX) -o std_speed_set tests/std_speed_set.o $(CXXFLAGS)



else: algorithm iterator_traits pair random_access_iterator reverse_iterator



algorithm: ft_algorithm std_algorithm

ft_algorithm:	tests/ft_algorithm.o
			$(CXX) -o ft_algorithm tests/ft_algorithm.o $(CXXFLAGS)

std_algorithm:	tests/std_algorithm.o
			$(CXX) -o std_algorithm tests/std_algorithm.o $(CXXFLAGS)



iterator_traits: ft_iterator_traits std_iterator_traits

ft_iterator_traits:	tests/ft_iterator_traits.o
			$(CXX) -o ft_iterator_traits tests/ft_iterator_traits.o $(CXXFLAGS)

std_iterator_traits:	tests/std_iterator_traits.o
			$(CXX) -o std_iterator_traits tests/std_iterator_traits.o $(CXXFLAGS)



pair: ft_pair std_pair

ft_pair:	tests/ft_pair.o
			$(CXX) -o ft_pair tests/ft_pair.o $(CXXFLAGS)

std_pair:	tests/std_pair.o
			$(CXX) -o std_pair tests/std_pair.o $(CXXFLAGS)



random_access_iterator: ft_random_access_iterator std_random_access_iterator

ft_random_access_iterator:	tests/ft_random_access_iterator.o
			$(CXX) -o ft_random_access_iterator tests/ft_random_access_iterator.o $(CXXFLAGS)

std_random_access_iterator:	tests/std_random_access_iterator.o
			$(CXX) -o std_random_access_iterator tests/std_random_access_iterator.o $(CXXFLAGS)



reverse_iterator: ft_reverse_iterator std_reverse_iterator

ft_reverse_iterator:	tests/ft_reverse_iterator.o
			$(CXX) -o ft_reverse_iterator tests/ft_reverse_iterator.o $(CXXFLAGS)

std_reverse_iterator:	tests/std_reverse_iterator.o
			$(CXX) -o std_reverse_iterator tests/std_reverse_iterator.o $(CXXFLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_VECTOR)
	$(RM) $(OBJS_STACK)
	$(RM) $(OBJS_MAP)
	$(RM) $(OBJS_SET)
	$(RM) $(OBJS_ELSE)

fclean:	clean
		$(RM) $(NAME)
		$(RM) ft_vector std_vector ft_speed_vector std_speed_vector
		$(RM) ft_stack std_stack ft_speed_stack std_speed_stack
		$(RM) ft_map std_map ft_speed_map std_speed_map
		$(RM) ft_set std_set ft_speed_set std_speed_set
		$(RM) ft_algorithm std_algorithm
		$(RM) ft_iterator_traits std_iterator_traits
		$(RM) ft_pair std_pair
		$(RM) ft_random_access_iterator std_random_access_iterator
		$(RM) ft_reverse_iterator std_reverse_iterator

re: clean all

.PHONY: all clean re fclean
