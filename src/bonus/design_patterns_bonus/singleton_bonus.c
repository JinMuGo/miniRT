/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:31:18 by jgo               #+#    #+#             */
/*   Updated: 2023/07/13 14:25:00 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "defs_bonus.h"

static inline void	_init_mlx_assets(t_mlx_assets *mlx_assets)
{
	mlx_assets->mlx = mlx_init();
	mlx_assets->win = mlx_new_window(mlx_assets->mlx, WIN_WIDTH, WIN_HEIGHT,
			"miniRT_bonus");
	mlx_assets->img.img = mlx_new_image(mlx_assets->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_assets->img.addr = mlx_get_data_addr(mlx_assets->img.img,
			&mlx_assets->img.bits_per_pixel, &mlx_assets->img.line_length,
			&mlx_assets->img.endian);
}

t_meta	*singleton(void)
{
	static t_meta	*_meta;

	if (_meta != NULL)
		return (_meta);
	_meta = ft_calloc(1, sizeof(t_meta));
	_init_mlx_assets(&_meta->mlx_assets);
	return (_meta);
}
