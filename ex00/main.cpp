#include "easyfind.hpp"

#include <iostream>
#include <vector>

template <typename T>
void print_vector(const std::vector<T>& vec)
{
	typename std::vector<T>::const_iterator start = vec.begin();
	typename std::vector<T>::const_iterator end = vec.end();

	for (typename std::vector<T>::const_iterator it = start; it != end; ++it)
	{
		std::cout << "vec[" << (it - start) << "] = " << *it << std::endl;
	}
}

template <typename T>
void print_size_vector(const std::vector<T>& vec)
{
	typename std::vector<T>::const_iterator end = vec.end();

	std::cout << "Vector is from: " << &vec << " -> " << &end << std::endl;
	std::cout << "Vector has: " << vec.size() << " values" << std::endl;
}

int main()
{
	std::vector<int> vec;

	for(int i = 0; i < 100; ++i)
		vec.push_back(i * 2);

	print_vector(vec);
	std::cout << std::endl;
	
	print_size_vector(vec);
	std::cout << std::endl;

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 5);
		std::cout << "Found value at: " << &it << " -> " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
    return 0;
}
