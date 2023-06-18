/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:33:45 by jgo               #+#    #+#             */
/*   Updated: 2023/06/15 13:24:08 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "tensor.h"

bool	root_formula(double a, double b, double c, double root[2])
{
	const double	d = b * b - 4 * a * c;

	if (d < 0 || fabs(a) < EPSILON)
		return (false);
	root[0] = (-b - sqrt(d)) / (2 * a);
	root[1] = (-b + sqrt(d)) / (2 * a);
	return (true);
}
