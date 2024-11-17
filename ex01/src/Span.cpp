/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:39:57 by jyap              #+#    #+#             */
/*   Updated: 2024/11/17 12:52:28 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "../inc/Span.hpp"

Span::Span(unsigned int N) : max_size(N), storage(0)
{}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span &Span::operator=(const Span &copy)
{
	this->max_size = copy.max_size;
	this->storage = copy.storage;
	return (*this);
}

Span::~Span(void)
{}

void Span::addNumber(int nbr)
{
	if (this->storage.size() == this->max_size)
		throw Span::BeyondMaxSize();
	this->storage.push_back(nbr);
}

void Span::addRandomNumbers(unsigned int quantity)
{
	srand(time(NULL));
	try
	{
		for (unsigned int i = 0; i < quantity; i++)
			this->addNumber(rand());
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int Span::shortestSpan(void)
{
	std::vector<int> v = this->storage;

	if (v.size() < 2)
	{
		throw Span::NotEnoughElementsException();
	}

	std::sort(v.begin(), v.end());
	int shortest_gap = v.at(1) - v.at(0);

	std::vector<int>::iterator i;
	for (i = v.begin(); i != v.end() - 1; i++)
	{
		if (*(i + 1) - *i < shortest_gap)
			shortest_gap = *(i + 1) - *i; 
	}
	return (shortest_gap);
}

int Span::longestSpan(void)
{
	std::vector<int> v = this->storage;

	if (v.size() < 2)
		throw Span::NotEnoughElementsException();

	int min = *std::min_element(v.begin(), v.end());
	int max = *std::max_element(v.begin(), v.end());

	return (max - min);
}

void Span::printStorage(void)
{
	std::vector<int> v = this->storage;
	std::vector<int>::iterator i;

	std::cout << "storage = ";
	for (i = v.begin(); i != v.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}

const char* Span::BeyondMaxSize::what(void) const throw()
{
	return "Beyond vector's max size.";
}

const char* Span::NotEnoughElementsException::what(void) const throw()
{
	return "Vector must have at least 2 elements.";
}