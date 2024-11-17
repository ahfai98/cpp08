/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:47:42 by jyap              #+#    #+#             */
/*   Updated: 2024/11/17 12:53:54 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "../inc/easyfind.hpp"

int main(void)
{
	// VECTOR //
	std::vector<int> v1;
	for (size_t i = 0; i <= 10; i += 1) {
		v1.push_back(i);
	}

	std::cout << "v1 = ";
	for (std::vector<int>::iterator i = v1.begin(), e = v1.end(); i != e; i += 1) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	// will find
	std::cout << "Element Found Test" << std::endl;
	try 
	{
		easyfind(v1, 0);
		std::cout << "Element 0 was found in container." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "=======================" << std::endl;
	std::cout << "Element Not Found Test" << std::endl;
	// will raise EasyFindException
	try
	{
		easyfind(v1, 20);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return EXIT_SUCCESS;
}
