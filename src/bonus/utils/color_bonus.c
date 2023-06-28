/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:10:08 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/25 21:37:25 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs_bonus.h"
#include "minirt_bonus.h"
#include "utils_bonus.h"

static inline uint32_t	_color_calc(double rgba)
{
	return (0xFF * clamp(rgba, 0.0, 0.999));
}

uint32_t	rgba_to_color(t_rgba rgba)
{
	return (_color_calc(rgba.r) << 24 |
			_color_calc(rgba.g) << 16 |
			_color_calc(rgba.b) << 8 |
			_color_calc(rgba.a));
}

t_rgba	rgba_init_int(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	const t_rgba rgba = {
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

t_rgba	color_to_rgba(uint8_t *color)
{
	const uint8_t r = *color++;
	const uint8_t g = *color++;
	const uint8_t b = *color++;

	return (rgba_init_int(r, g, b, 0xFF));
}