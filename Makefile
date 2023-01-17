# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 20:02:48 by aessakhi          #+#    #+#              #
#    Updated: 2023/01/17 22:12:17 by aessakhi         ###   ########.fr        #
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
OUTPUT_DIR = output

SRCS =	main.cpp

SRCS_VECTOR = tests/ft_vector.cpp tests/std_vector.cpp tests/std_speed_vector.cpp tests/ft_speed_vector.cpp

SRCS_STACK = tests/ft_stack.cpp tests/std_stack.cpp tests/std_speed_stack.cpp tests/ft_speed_stack.cpp

SRCS_MAP = tests/ft_map.cpp tests/std_map.cpp tests/std_speed_map.cpp tests/ft_speed_map.cpp

SRCS_SET = tests/ft_set.cpp tests/std_set.cpp tests/std_speed_set.cpp tests/ft_speed_set.cpp

SRCS_ELSE = tests/ft_algorithm.cpp tests/std_algorithm.cpp \
			tests/ft_iterator_traits.cpp tests/std_iterator_traits.cpp tests/ft_pair.cpp tests/std_pair.cpp \
			tests/ft_random_access_iterator.cpp tests/std_random_access_iterator.cpp tests/ft_reverse_iterator.cpp tests/std_reverse_iterator.cpp

RM =	rm -rf

$(NAME):	vector stack map set else $(OBJS)
			$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS)

all: $(NAME)

vector:	$(OBJS_VECTOR)
		@mkdir -p $(OUTPUT_DIR)/vector
		$(CXX) -o $(OUTPUT_DIR)/vector/ft_vector tests/ft_vector.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/vector/std_vector tests/std_vector.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/vector/std_speed_vector tests/std_speed_vector.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/vector/ft_speed_vector tests/ft_speed_vector.o $(CXXFLAGS)

stack:	$(OBJS_STACK)
		@mkdir -p $(OUTPUT_DIR)/stack
		$(CXX) -o $(OUTPUT_DIR)/stack/ft_stack tests/ft_stack.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/stack/std_stack tests/std_stack.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/stack/std_speed_stack tests/std_speed_stack.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/stack/ft_speed_stack tests/ft_speed_stack.o $(CXXFLAGS)

map:	$(OBJS_MAP)
		@mkdir -p $(OUTPUT_DIR)/map
		$(CXX) -o $(OUTPUT_DIR)/map/ft_map tests/ft_map.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/map/std_map tests/std_map.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/map/std_speed_map tests/std_speed_map.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/map/ft_speed_map tests/ft_speed_map.o $(CXXFLAGS)

set:	$(OBJS_SET)
		@mkdir -p $(OUTPUT_DIR)/set
		$(CXX) -o $(OUTPUT_DIR)/set/ft_set tests/ft_set.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/set/std_set tests/std_set.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/set/std_speed_set tests/std_speed_set.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/set/ft_speed_set tests/ft_speed_set.o $(CXXFLAGS)

else:	$(OBJS_ELSE)
		@mkdir -p $(OUTPUT_DIR)/else
		$(CXX) -o $(OUTPUT_DIR)/else/std_algorithm tests/std_algorithm.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/else/ft_algorithm tests/ft_algorithm.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/else/std_iterator_traits tests/std_iterator_traits.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/else/ft_iterator_traits tests/ft_iterator_traits.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/else/std_pair tests/std_pair.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/else/ft_pair tests/ft_pair.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/else/std_random_access_iterator tests/std_random_access_iterator.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/else/ft_random_access_iterator tests/ft_random_access_iterator.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/else/std_reverse_iterator tests/std_reverse_iterator.o $(CXXFLAGS)
		$(CXX) -o $(OUTPUT_DIR)/else/ft_reverse_iterator tests/ft_reverse_iterator.o $(CXXFLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_VECTOR)
	$(RM) $(OBJS_STACK)
	$(RM) $(OBJS_MAP)
	$(RM) $(OBJS_SET)
	$(RM) $(OBJS_ELSE)

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(OUTPUT_DIR)

re: clean all

.PHONY: all clean re fclean
