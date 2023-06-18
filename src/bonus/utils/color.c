/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:10:08 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/18 17:58:27 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "utils.h"

static inline uint32_t	_color_calc(double rgba)
{
	return (0xFF * clamp(rgba, 0.0, 0.999));
}

uint32_t	rgba_to_color(t_rgba rgba)
{
	return (_color_calc(rgba.r) << 24 | \
			_color_calc(rgba.g) << 16 | \
			_color_calc(rgba.b) << 8 | \
			_color_calc(rgba.a));
}

t_rgba	rgba_init_int(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	const t_rgba	rgba = {
		(double)r / 0xFF,
		(double)g / 0xFF,
		(double)b / 0xFF,
		(double)a / 0xFF};

	return (rgba);
}

t_rgba	rgba_init_double(double r, double g, double b, double a)
{
	const t_rgba	rgba = {r, g, b, a};

	return (rgba);
}
