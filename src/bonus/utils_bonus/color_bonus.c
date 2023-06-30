/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:10:08 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/30 20:14:13 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs_bonus.h"
#include "minirt_bonus.h"
#include "utils_bonus.h"

static inline uint32_t	_color_calc(double rgb)
{
	return (0xFF * clamp(rgb, 0, 1));
}

uint32_t	rgba_to_color(t_rgb rgb)
{
	return (_color_calc(rgb.x) << 24
		| _color_calc(rgb.y) << 16
		| _color_calc(rgb.z) << 8
		| 0xFF);
}

t_rgb	rgb_init_int(const int r, const int g, const int b)
{
	const t_rgb	rgb = {
		(double)r / 0xFF,
		(double)g / 0xFF,
		(double)b / 0xFF};

	return (rgb);
}

t_rgb	rgba_min(t_rgb a, t_rgb b)
{
	if (a.x > b.x)
		a.x = b.x;
	if (a.y > b.y)
		a.y = b.y;
	if (a.z > b.z)
		a.z = b.z;
	return (a);
}

t_rgb	color_to_rgba(uint8_t *color)
{
	const uint8_t	r = *color++;
	const uint8_t	g = *color++;
	const uint8_t	b = *color++;

	return (rgb_init_int(r, g, b));
}
