/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:51:08 by jgo               #+#    #+#             */
/*   Updated: 2023/06/08 16:12:33 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"

static inline int	_color_calc(double rgb)
{
	const int	color = 256 * rgb;

	if (color > 255)
		return (255);
	return (color);
}

int	rgb_to_color(t_rgb rgb)
{
	return (_color_calc(rgb.r) << 24 |
			_color_calc(rgb.g) << 16 |
			_color_calc(rgb.b) << 8);
}