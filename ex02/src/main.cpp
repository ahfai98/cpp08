/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:47:42 by jyap              #+#    #+#             */
/*   Updated: 2024/11/17 13:25:43 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "../inc/MutantStack.hpp"
#include <list>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	std::cout << "Test for Mutant Stack" << std::endl;
	MutantStack<int> ms;
	ms.push(1);
	ms.push(2);
	ms.push(3);
	ms.push(4);
	ms.push(5);

	MutantStack<int>::iterator begin = ms.begin();
	MutantStack<int>::iterator end = ms.end();

	std::cout << "stack = ";
	while (begin != end)
	{
		std::cout << *begin << " ";
		begin++;
	}

	std::cout << std::endl;

	std::cout << "=======================" << std::endl;
	std::cout << "Test for List" << std::endl;
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);

	std::list<int>::iterator beginl = lst.begin();
	std::list<int>::iterator endl = lst.end();

	std::cout << "list = ";
	while (beginl != endl)
	{
		std::cout << *beginl << " ";
		beginl++;
	}
	std::cout << std::endl;
	return EXIT_SUCCESS;
}