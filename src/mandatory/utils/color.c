/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:10:08 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/29 10:05:56 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "utils.h"

static inline uint32_t	_color_calc(const float rgb)
{
	return (0xFF * clamp(rgb, 0.0, 1));
}

uint32_t	rgba_to_color(t_rgb rgb)
{
	return (_color_calc(rgb.x) << 24 | \
			_color_calc(rgb.y) << 16 | \
			_color_calc(rgb.z) << 8 | \
			0xFF);
}

t_rgb	rgba_init_int(const int r, const int g, const int b)
{
	const t_rgb	rgb = {
		(float)r / 0xFF,
		(float)g / 0xFF,
		(float)b / 0xFF};

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
