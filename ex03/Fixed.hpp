/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:23:54 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/29 20:31:39 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class	Fixed
{
	public:
		// Constructors
		Fixed(void);
		Fixed(Fixed const &fixed);
		Fixed(int const &val);
		Fixed(float const &val);
		// Destructor
		~Fixed(void);
		// Assignation operator
		Fixed				&operator=(Fixed const &fixed);
		// Comparison operators
		bool				operator<(Fixed const &fixed) const;
		bool				operator>(Fixed const &fixed) const;
		bool				operator<=(Fixed const &fixed) const;
		bool				operator>=(Fixed const &fixed) const;
		bool				operator==(Fixed const &fixed) const;
		bool				operator!=(Fixed const &fixed) const;
		// Arithmetic operators
		Fixed				operator+(Fixed const &fixed) const;
		Fixed				operator-(Fixed const &fixed) const;
		Fixed				operator*(Fixed const &fixed) const;
		Fixed				operator/(Fixed const &fixed) const;
		// Unary operators
		Fixed				&operator++(void);
		Fixed				operator++(int);
		Fixed				&operator--(void);
		Fixed				operator--(int);
		// Others functions
		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed const	&min(Fixed const &a, Fixed const &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static Fixed const	&max(Fixed const &a, Fixed const &b);
		// Getters
		int					getRawBits(void) const;
		float				toFloat(void) const;
		int					toInt(void) const;
		// Setter
		void				setRawBits(int const raw);
	private:
		int					_rawBits;
		static int const	_fractBits = 8;
};

// Insertion operator
std::ostream	&operator<<(std::ostream &ostream, Fixed const &fixed);

#endif
