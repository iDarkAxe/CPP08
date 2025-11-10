#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <exception>



class Span
{
private:
	std::vector<unsigned int> _numbers;
	size_t _max_size;
	Span();

public:
	Span(size_t size);
	Span(std::vector<unsigned int>::const_iterator begin, std::vector<unsigned int>::const_iterator end);
	~Span();
	Span(const Span &f);
	Span &operator=(const Span &other);

	void addNumber(unsigned int number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	std::vector<unsigned int>::const_iterator begin() const;
	std::vector<unsigned int>::const_iterator end() const;

	void printNumbers() const;

	class TooManyNumbersException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class NeedMoreNumbersException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

#endif
