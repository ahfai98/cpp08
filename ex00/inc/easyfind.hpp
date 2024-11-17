/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:31:02 by jyap              #+#    #+#             */
/*   Updated: 2024/11/17 12:25:45 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <string>
# include <exception>
# include <algorithm>

class EasyFindException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("easyfind: exception: element not found within container");
		}
};

template<typename T>
bool easyfind(const T &container, int to_find)
{
	if (std::find(container.begin(), container.end(), to_find) == container.end())
		throw EasyFindException();
	else
		return true;
}

#endif
