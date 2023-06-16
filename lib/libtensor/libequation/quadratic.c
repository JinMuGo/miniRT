/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:33:45 by jgo               #+#    #+#             */
/*   Updated: 2023/06/16 11:03:52 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tensor.h"

bool	root_formula(double a, double b, double c, double root[2])
{
	const double	d = b * b - 4 * a * c;

	if (d < 0 || fabs(a) < EPSILON)
		return (false);
	root[0] = (-b - sqrt(d)) / 2 * a;
	root[1] = (-b + sqrt(d)) / 2 * a;
	return (true);
}
