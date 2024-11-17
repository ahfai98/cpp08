/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:47:42 by jyap              #+#    #+#             */
/*   Updated: 2024/11/17 13:06:42 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "../inc/Span.hpp"

int main(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.printStorage();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// Pushing beyond N elements
	std::cout << "===========================" << std::endl;
	std::cout << "Test adding beyond max storage" << std::endl;
	try
	{
		sp.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// Trying to get a span with less than 2 elements on the vector
	std::cout << "===========================" << std::endl;
	std::cout << "Test get Span with only 1 number" << std::endl;
	Span sp1 = Span(1);
	sp1.addNumber(1);
	try
	{
		std::cout << sp1.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "===========================" << std::endl;
	std::cout << "Test with 10000 random numbers" << std::endl;
	Span sp2 = Span(10);
	try
	{
		sp2.addRandomNumbers(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "sp2 ";
	sp2.printStorage();
	try
	{
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return EXIT_SUCCESS;
}
