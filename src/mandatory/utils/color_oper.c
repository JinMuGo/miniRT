/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:58:12 by jgo               #+#    #+#             */
/*   Updated: 2023/06/18 18:00:00 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"

t_rgba	rgba_scalar_multi(t_rgba rgba, double scalar)
{
	return (rgba_init_double(
			rgba.r * scalar,
			rgba.g * scalar,
			rgba.b * scalar,
			rgba.a));
}

t_rgba	rgba_scalar_divide(t_rgba rgba, double scalar)
{
	return (rgba_init_double(
			rgba.r * (1.0 / scalar),
			rgba.g * (1.0 / scalar),
			rgba.b * (1.0 / scalar),
			rgba.a));
}

t_rgba	rgba_multi(t_rgba a, t_rgba b)
{
	return (rgba_init_double(a.r * b.r, a.g * b.g, a.b * b.b, 1));
}

t_rgba	rgba_plus(t_rgba a, t_rgba b)
{
	return (rgba_init_double(a.r + b.r, a.g + b.g, a.b + b.b, 1));
}

t_rgba	rgba_min(t_rgba a, t_rgba b)
{
	if (a.r > b.r)
		a.r = b.r;
	if (a.g > b.g)
		a.g = b.g;
	if (a.b > b.b)
		a.b = b.b;
	return (a);
}
