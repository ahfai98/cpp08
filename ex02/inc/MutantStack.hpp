/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:31:02 by jyap              #+#    #+#             */
/*   Updated: 2024/11/17 13:24:50 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack(void);
		MutantStack(const MutantStack &copy);
		MutantStack &operator=(const MutantStack &copy);
		~MutantStack(void);
		iterator begin(void);
		iterator end(void);
};

template<typename T>
MutantStack<T>::MutantStack(void)
{
	std::cout << "[MutantStack] default constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const& copy)
{
	*this = copy;
	std::cout << "[MutantStack] copy constructor called" << std::endl;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const& copy)
{
	if (this != &copy)
		std::stack<int>::operator=(copy);
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout << "[MutantStack] default destructor called" << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

#endif
