/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:31:02 by jyap              #+#    #+#             */
/*   Updated: 2024/11/17 12:39:01 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdint.h>
# include <exception>
# include <vector>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span(void);
		void addNumber(int nbr);
		void addRandomNumbers(unsigned int quantity);
		int shortestSpan(void);
		int longestSpan(void);
		void printStorage(void);
		class NotEnoughElementsException : public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};
		class BeyondMaxSize : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		unsigned int max_size;
		std::vector<int> storage;
		Span();
};

#endif
