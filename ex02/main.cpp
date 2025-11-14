#include "MutantStack.hpp"

#include <iostream>
#include <list>

#ifndef DEBUG
# define DEBUG 1
#endif

/* Function prototypes needed for mandatory main */
void mutant_stack_list_test(void);
void std_list_test(void);
/* Function prototypes for additional tests */
void enhanced_main(void);
void simple_test(void);
void simple_coplien_test(void);

/* Mandatory main function */
int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}


/* More tests */
// int main()
// {
// 	enhanced_main();
// 	simple_test();
// 	simple_coplien_test();
// 	return (0);
// }

/* Same but with std::list */
/*
	push becomes push_back
	pop becomes pop_back
	top becomes back
*/
void std_list_test()
{
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);
	std::list<int>::iterator it = mlist.begin();
	std::list<int>::iterator ite = mlist.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void mutant_stack_list_test()
{
	MutantStack<int, std::list<int> > mstack_list;
	mstack_list.push(5);
	mstack_list.push(17);
	std::cout << mstack_list.top() << std::endl;
	mstack_list.pop();
	std::cout << mstack_list.size() << std::endl;
	mstack_list.push(3);
	mstack_list.push(5);
	mstack_list.push(737);
	//[...]
	mstack_list.push(0);
	MutantStack<int, std::list<int> >::iterator it = mstack_list.begin();
	MutantStack<int, std::list<int> >::iterator ite = mstack_list.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void enhanced_main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element is: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Stack size is: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Top element is: " << mstack.top() << std::endl;

	/* It is possible that The addresses are not growing, 
	it's because a deque is not a contiguous container 
	(it can but it is not guaranteed, see it as a linked list, 
	all elements have quasi-random adresses) */
	size_t count = 0;
	while (it != ite)
	{
		std::cout << "Value [" << count << "] at " << &(*it) << " is : " << *it << std::endl;
		++it;
		count++;
	}
	std::cout << "The value '" << mstack.top() << "' will be popped." << std::endl;
	mstack.pop();
	std::stack<int> s(mstack);
	while (!s.empty())
	{
		std::cout << "Stack top is: " << s.top() << std::endl;
		s.pop();
	}
}

void simple_test(void)
{
	MutantStack<int> mstack;
	for (int i = 0; i < 10; ++i)
	{
		mstack.push(i);
		if (DEBUG)
			std::cout << "Pushed: " << i << std::endl;
	}
	std::cout << "Value at top is: " << mstack.top() << std::endl;

	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << "Value at " << &(*it) << " is : " << *it << std::endl;
	}
}

void simple_coplien_test()
{
	MutantStack<int> mstack;

	for (int i = 0; i < 10; ++i)
	{
		mstack.push(i);
		if (DEBUG)
			std::cout << "Pushed: " << i << std::endl;
	}
	MutantStack<int> otherStack(mstack);
	while (!otherStack.empty())
	{
		std::cout << "Stack top is: " << otherStack.top() << std::endl;
		otherStack.pop();
	}
	std::cout << "Before pushing 42, top is: " << mstack.top() << std::endl;
	mstack.push(42);
	std::cout << "After pushing 42, top is: " << mstack.top() << std::endl;
	std::cout << std::endl;
	{
		MutantStack<int> *copyStack;
		copyStack = new MutantStack<int>(mstack);
		for (int i = 10; i < 20; ++i)
		{
			copyStack->push(i * 2);
			if (DEBUG)
				std::cout << "Pushed: " << i << std::endl;
		}

		MutantStack<int>::iterator it = copyStack->begin();
		MutantStack<int>::iterator ite = copyStack->end();
		std::cout << "Top element is: " << copyStack->top() << std::endl;

		// The addresses can not being growing because a deque is not a contiguous container (can but it is not guaranteed)
		size_t count = 0;
		while (it != ite)
		{
			std::cout << "Value [" << count << "] at " << &(*it) << " is : " << *it << std::endl;
			++it;
			count++;
		}
		otherStack = *copyStack;
		delete copyStack;
	}
	std::cout << std::endl;
	MutantStack<int>::iterator it = otherStack.begin();
	MutantStack<int>::iterator ite = otherStack.end();
	std::cout << "Top element is: " << otherStack.top() << std::endl;

	size_t count = 0;
	while (it != ite)
	{
		std::cout << "Value [" << count << "] at " << &(*it) << " is : " << *it << std::endl;
		++it;
		count++;
	}
{
	MutantStack<int>::reverse_iterator it = otherStack.rbegin();
	MutantStack<int>::reverse_iterator ite = otherStack.rend();
	std::cout << "Top element is: " << otherStack.top() << std::endl;

	count = 0;
	while (it != ite)
	{
		std::cout << "Value [" << count << "] at " << &(*it) << " is : " << *it << std::endl;
		++it;
		count++;
	}
}
}
