/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:33:26 by jgo               #+#    #+#             */
/*   Updated: 2023/07/13 17:59:16 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"

static inline bool	_invalid_dot(const int x, const int y)
{
	if (x < 0 || x > WIN_WIDTH)
		return (true);
	if (y < 0 || y > WIN_HEIGHT)
		return (true);
	return (false);
}

static inline void	_set_color(char *offset, const int endian,
		const uint32_t color, const int alpha)
{
	if (endian)
	{
		offset[0] = alpha;
		offset[1] = (color >> 24);
		offset[2] = (color >> 16);
		offset[3] = (color >> 8);
	}
	else
	{
		offset[0] = (color >> 8);
		offset[1] = (color >> 16);
		offset[2] = (color >> 24);
		offset[3] = alpha;
	}
}

void	my_pixel_put(t_mlx_assets *mlx_assets, const uint32_t x,
		const uint32_t y, const uint32_t color)
{
	const int	offset = y * mlx_assets->img.line_length + x * mlx_assets->img.bits_per_pixel / 8;

	if (_invalid_dot(x, y))
		return ;
	_set_color(&mlx_assets->img.addr[offset],
		mlx_assets->img.endian,
		color, 1);
}
