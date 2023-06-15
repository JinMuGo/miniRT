/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:10:08 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/15 09:13:50 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"

static inline uint32_t	_color_calc(double rgba)
{
	return (0xFF * rgba);
}

uint32_t	rgba_to_color(t_rgba rgba)
{
	return (_color_calc(rgba.r) << 24 | \
			_color_calc(rgba.g) << 16 | \
			_color_calc(rgba.b) << 8 | \
			_color_calc(rgba.a));
}

t_rgba	rgba_init(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	const t_rgba	rgba = {
		(double)r / 0xFF,
		(double)g / 0xFF,
		(double)b / 0xFF,
		(double)a / 0xFF};

	return (rgba);
}

t_rgba rgba_init2(double r, double g, double b, double a)
{
	const t_rgba	rgba = {r, g, b, a};

	return (rgba);
}

t_rgba	rgba_scalar_multi(t_rgba rgba, double scalar)
{
	return (rgba_init2(rgba.r * scalar, rgba.g * scalar, rgba.b * scalar, rgba.a));
}

t_rgba	rgba_multi(t_rgba a, t_rgba b)
{
	return (rgba_init2(a.r * b.r, a.g * b.g, a.b * b.b, 1));
}
