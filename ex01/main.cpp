#include "Span.hpp"

#include <iostream>
#include <vector>

#ifndef DEBUG
# define DEBUG 0
#endif

// Function prototypes for additional tests
void testing_with_more_values_than_max();
void underfilled_span();
void fill_with_range();
void fill_with_range_span();
void test_with_20000_numbers();
void simple_coplien_test();

// Mandatory main function to demonstrate span
int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}

// More tests
// int main()
// {
// 	testing_with_more_values_than_max();
// 	underfilled_span();
// 	fill_with_range();
// 	fill_with_range_span();
// 	test_with_20000_numbers();
// 	simple_coplien_test();
// 	return (0);
// }

void testing_with_more_values_than_max()
{
	Span sp = Span(5);
	try {
		sp.addNumber(6);
		if (DEBUG) 
			std::cout << "Added 6" << std::endl;
		sp.addNumber(3);
		if (DEBUG) 
			std::cout << "Added 3" << std::endl;
		sp.addNumber(17);
		if (DEBUG) 
			std::cout << "Added 17" << std::endl;
		sp.addNumber(9);
		if (DEBUG) 
			std::cout << "Added 9" << std::endl;
		sp.addNumber(11);
		if (DEBUG) 
			std::cout << "Added 11" << std::endl;
		sp.addNumber(12); // This should throw TooManyNumbersException
		if (DEBUG) 
			std::cout << "Added 12" << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void underfilled_span()
{
	Span sp = Span(5);
	sp.addNumber(17);
	try {
		std::cout << sp.shortestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void fill_with_range()
{
	std::vector<unsigned int> numbers;
	numbers.push_back(6);
	numbers.push_back(3);
	numbers.push_back(17);
	numbers.push_back(9);
	numbers.push_back(11);
	
	Span sp(numbers.begin(), numbers.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void fill_with_range_span()
{
	Span *filled;
	try
	{
		filled = new Span(10);
	}
	catch (const std::exception &e)
	{
		std::cout << "New failed: " << e.what() << std::endl;
		return;
	}

	for (unsigned int i = 0; i < 10; ++i)
	{
		try {
			filled->addNumber(i * 2);
			if (DEBUG) 
				std::cout << "Added " << i * 2 << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	filled->printNumbers();
	Span sp(filled->begin(), filled->end());
	delete filled;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	sp.printNumbers();
}

void test_with_20000_numbers()
{
	Span sp(20000);
	for (unsigned int i = 0; i < 20000; ++i)
	{
		try {
			sp.addNumber(i * 2);
			if (DEBUG) 
				std::cout << "Added " << i << std::endl;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	sp.printNumbers();
}

void simple_coplien_test()
{
	Span sp1(5);
	sp1.addNumber(1);
	sp1.addNumber(2);
	sp1.addNumber(3);
	sp1.addNumber(4);
	sp1.addNumber(5);
	
	Span sp2(sp1); // Copy constructor
	std::cout << "Copy constructor test:" << std::endl;
	sp2.printNumbers();

	Span sp3 = sp2; // Assignment operator
	std::cout << "Assignment operator test:" << std::endl;
	sp3.printNumbers();

	Span *sp4 = new Span(sp3);
	std::cout << "Copy with new operator test:" << std::endl;
	sp4->printNumbers();
	delete sp4;
}
