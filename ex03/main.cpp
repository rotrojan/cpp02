/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:47:55 by rotrojan          #+#    #+#             */
/*   Updated: 2021/11/29 21:23:02 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Point.hpp"

void	print_result(Point const a, Point const b, Point const c, Point const d)
{
	std::cout << "Triangle ABC" << std::endl;
	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;
	std::cout << "C = " << c << std::endl;
	std::cout << "Point D (" << d << ") is ";
	if (bsp(a, b, c, d) == false)
		std::cout << "not ";
	std::cout << "in the triangle" << std::endl;
}

int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(0.0f, 7.0f);
	Point c(3.5f, 4.0f);
	Point d(3.5f, 0.0f);
	Point e(1.0f, 3.5);
	Point f(0.0f, 3.5);
	print_result(a, b, c, d);
	std::cout << std::endl;
	print_result(a, b, c, e);
	std::cout << std::endl;
	print_result(a, b, c, f);
	return (EXIT_SUCCESS);
}
