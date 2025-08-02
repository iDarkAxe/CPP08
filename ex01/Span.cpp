#include "Span.hpp"

Span::Span()
{
	_max_size = 0;
}

Span::Span(size_t size)
{
	_max_size = size;
}

Span::Span(std::vector<unsigned int>::const_iterator begin, std::vector<unsigned int>::const_iterator end)
{
	_max_size = std::distance(begin, end);
	_numbers.assign(begin, end);
}

Span::~Span()
{
	;
}

Span::Span(const Span &other)
{
	this->_max_size = other._max_size;
	this->_numbers = other._numbers;
}

Span &Span::operator=(const Span &other)
{
	this->_max_size = other._max_size;
	this->_numbers = other._numbers;
	return (*this);
}

void Span::addNumber(unsigned int number)
{
	if (_numbers.size() >= _max_size)
		throw TooManyNumbersException();
	_numbers.push_back(number);
}

// There is 2 numbers between 3 and 6 : 4 and 5
// So the shortest span is 2
unsigned int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw NeedMoreNumbersException();
	std::vector<unsigned int> sorted_numbers = _numbers;
	std::sort(sorted_numbers.begin(), sorted_numbers.end());
	return (sorted_numbers[1] - sorted_numbers[0] - 1);
}

// There is 13 numbers between 3 and 17 : 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
// So the longest span should be 13 but example shows 14
unsigned int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw NeedMoreNumbersException();
	return (*std::max_element(this->_numbers.begin(), this->_numbers.end()) - *std::min_element(this->_numbers.begin(), this->_numbers.end()));
}

std::vector<unsigned int>::const_iterator Span::begin() const
{
	return _numbers.begin();
}

std::vector<unsigned int>::const_iterator Span::end() const
{
	return _numbers.end();
}

const char * Span::TooManyNumbersException::what() const throw()
{
	return "Too many numbers already in container";
}

const char * Span::NeedMoreNumbersException::what() const throw()
{
	return "Not enough numbers in container";
}

#include <iostream>

void Span::printNumbers() const
{
	std::vector<unsigned int>::const_iterator start = _numbers.begin();
	std::vector<unsigned int>::const_iterator end = _numbers.end();

	for (std::vector<unsigned int>::const_iterator it = start; it != end; ++it)
	{
		std::cout << "vec[" << (it - start) << "] = " << *it << std::endl;
	}
}
