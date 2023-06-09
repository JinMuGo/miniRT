/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:51:08 by jgo               #+#    #+#             */
/*   Updated: 2023/06/09 16:54:55 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"

static inline uint32_t	_color_calc(double rgb)
{
	return (0xFF * rgb);
}

uint32_t	rgb_to_color(t_rgba rgb)
{
	return (_color_calc(rgb.r) << 24 | \
			_color_calc(rgb.g) << 16 | \
			_color_calc(rgb.b) << 8 | \
			_color_calc(rgb.a));
}

t_rgba	rgb_init(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	const t_rgba	rgb = {
		(double)r / 0xFF,
		(double)g / 0xFF,
		(double)b / 0xFF,
		(double)a / 0xFF};

	return (rgb);
}
