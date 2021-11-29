/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:47:55 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/29 20:56:39 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << std::endl;

	Fixed d(-42);
	Fixed c(21);


	// Comparison tests
	std::cout << "(" << c << " < " << d << ") = " << (c < d) << std::endl;
	std::cout << "(" << c << " > " << d << ") = " << (c > d) << std::endl;
	std::cout << "(" << c << " <= " << d << ") = " << (c <= d) << std::endl;
	std::cout << "(" << c << " >= " << d << ") = " << (c >= d) << std::endl;
	std::cout << "(" << c << " == " << d << ") = " << (c == d) << std::endl;
	std::cout << "(" << c << " != " << d << ") = " << (c != d) << std::endl;
	std::cout << std::endl;
	// Arithmetic tests
	std::cout << c << " + " << d << " = " << (c + d) << std::endl;
	std::cout << c << " - " << d << " = " << (c - d) << std::endl;
	std::cout << c << " * " << d << " = " << (c * d) << std::endl;
	std::cout << c << " / " << d << " = " << (c / d) << std::endl;
	std::cout << std::endl;
	// Incrementation / decrementation tests
	std::cout << "c++ = " << c++ << std::endl;
	std::cout << "--c = " << --c << std::endl;
	std::cout << "++c = " << ++c << std::endl;
	std::cout << "c-- = " << c-- << std::endl;
	std::cout << "c = " << c << std::endl;
	// Min / max tests
	Fixed const const_c(c);
	Fixed const const_d(d);
	std::cout << "      min(" << c << ", " << d << ") = " << Fixed::min(c, d) << std::endl;
	std::cout << "const min(" << const_c << ", " << const_d << ") = " << Fixed::min(const_c, const_d) << std::endl;
	std::cout << "      max(" << c << ", " << d << ") = " << Fixed::max(c, d) << std::endl;
	std::cout << "const max(" << const_c << ", " << const_d << ") = " << Fixed::max(const_c, const_d) << std::endl;
	return (0);
}
