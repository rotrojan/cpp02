/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:23:54 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/29 15:59:01 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const &fixed);
		Fixed(int const &val);
		Fixed(float const &val);
		~Fixed(void);
		Fixed			&operator=(Fixed const &fixed);
		int				getRawBits(void) const;
		float			toFloat(void) const;
		int				toInt(void) const;
		void			setRawBits(int const raw);
	private:
		int					_rawBits;
		static int const	_fractBits = 8;
};

std::ostream	&operator<<(std::ostream &ostream, Fixed const &fixed);

#endif
