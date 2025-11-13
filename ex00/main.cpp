#include "easyfind.hpp"

#include <iostream>
#include <iomanip>
#include <vector>

#ifndef DEBUG
# define DEBUG 1
#endif

template <typename T>
void print_vector(const std::vector<T>& vec)
{
	typename std::vector<T>::const_iterator start = vec.begin();
	typename std::vector<T>::const_iterator end = vec.end();
	unsigned int power_of_10 = 0;
	for (size_t n = end - start; n >= 10; n /= 10)
		++power_of_10;
	for (typename std::vector<T>::const_iterator it = start; it != end; ++it)
	{
		if (DEBUG)
			std::cout << "vec[" << std::setw(power_of_10 + 1) << (it - start) << "] = " <<  *it << " -> " << &(*it) << std::endl;
		else
			std::cout << "vec[" << std::setw(power_of_10 + 1) << (it - start) << "] = " << *it << std::endl;
	}
}

template <typename T>
void print_size_vector(const std::vector<T>& vec)
{
	std::cout << "Vector data is: " << vec.data() << " -> " << vec.data() + vec.size() - 1 << std::endl;
	std::cout << "Vector has: " << vec.size() << " values" << std::endl;
}

int main()
{
	std::vector<int> vec;

	for(int i = 0; i < 20; ++i)
		vec.push_back(i * 2);

	print_vector(vec);
	std::cout << std::endl;
	
	print_size_vector(vec);
	std::cout << std::endl;

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 6);
		std::cout << "Found value at: " << &it << " -> " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
    return 0;
}
