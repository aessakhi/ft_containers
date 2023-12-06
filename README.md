# ft_containers

In this project, you will implement a few container types of the C++ standard template
library.
You have to take the structure of each standard container as reference. If a part of
the Orthodox Canonical form is missing in it, do not implement it.
As a reminder, you have to comply with the C++98 standard, so any later feature of
the containers MUST NOT be implemented, but every C++98 feature (even deprecated
ones) is expected.

Implement the following containers and turn in the necessary <container>.hpp files with
a Makefile:
- vector
You don’t have to do the vector<bool> specialization.
- map
- stack
It will use your vector class as default underlying container. But it must still be
compatible with other containers, the STL ones included.


You also have to implement:
- std::iterator_traits
- std::reverse_iterator
- std::enable_if
Yes, it is C++11 but you will be able to implement it in a C++98 manner.
This is asked so you can discover SFINAE.
- std::is_integral
- std::equal and/or std::lexicographical_compare
- std::pair
- std::make_pair
