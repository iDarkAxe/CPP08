#ifndef EASYFIND_HPP
#define EASYFIND_HPP

/* 
Écrivez une fonction template easyfind acceptant un type T. 
Elle prend deux paramètres. Le premier est de type T et le second un nombre entier.
Partant du principe que T est un container d’entiers, cette fonction doit trouver la
première occurrence du second paramètre dans le premier paramètre.

Si aucune occurrence n’a été trouvée, vous pouvez soit jeter une exception, 
soit retourner une valeur d’erreur de votre choix. 
Si vous avez besoin d’inspiration, jetez un oeil
au comportement des containers standards. 
Vous n’avez pas à gérer les containers associatifs.
*/

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
public:
	const char* what() const throw()
	{
		return "Value not found in container";
	}
};

/**
 * @brief Find the first occurrence of a value in a container.
 * Throws NotFoundException if the value is not found.
 *
 * @tparam T The container type.
 * @param container The container to search.
 * @param value The value to find.
 * @return T::iterator An iterator to the found value.
 */
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	else
		return it;
}

#endif
