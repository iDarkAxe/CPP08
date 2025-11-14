#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <list>
#include <exception>

/*
Implémentez une classe MutantStack. Elle sera implémentée en termes de la
std::stack. Elle offrira toutes ses fonctions membres avec en plus des itérateurs.
Bien entendu, implémentez et rendez vos propres tests afin de démontrer que tout
marche comme attendu.
*/

template<
    class T,
    class Container = std::deque<T>
>
class MutantStack : public std::stack<T, Container>
{
private:

public:
	MutantStack()
	{
		;
	}
	~MutantStack()
	{
		;
	}
	MutantStack(const MutantStack &f) : std::stack<T, Container>(f)
	{
		;
	}

	MutantStack &operator=(const MutantStack &other)
	{
		if (this != &other)
			std::stack<T, Container>::operator=(other);
		return *this;
	}
	
	typedef typename Container::iterator iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::const_reverse_iterator reverse_const_iterator;

	/* Iterators */
	/*
	this->c is the underlying container of the stack
	which is a deque by default, so we can use its iterators.
	*/
	typename Container::iterator begin() { return this->c.begin(); }
	typename Container::iterator end() { return this->c.end(); }
	typename Container::reverse_iterator rbegin() { return this->c.rbegin(); }
	typename Container::reverse_iterator rend() { return this->c.rend(); }
	typename Container::const_iterator begin() const { return this->c.begin(); }
	typename Container::const_iterator cbegin() const { return this->c.cbegin(); }
	typename Container::const_iterator end() const { return this->c.end(); }
	typename Container::const_iterator cend() const { return this->c.cend(); }
	typename Container::const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	typename Container::const_reverse_iterator crbegin() const { return this->c.crbegin(); }
	typename Container::const_reverse_iterator rend() const { return this->c.rend(); }
	typename Container::const_reverse_iterator crend() const { return this->c.crend(); }

	// void printNumbers() const;

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
