/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:31:18 by jgo               #+#    #+#             */
/*   Updated: 2023/05/25 19:41:16 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"

static inline void	_init_mlx_assets(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	mlx->img.img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(\
		mlx->img.img, &mlx->img.bpp, &mlx->img.line, &mlx->img.endian);
}

t_meta	*singleton(void)
{
	static t_meta	*_meta;

	if (_meta != NULL)
		return (_meta);
	_meta = ft_calloc(1, sizeof(t_meta));
	_init_mlx_assets(&_meta->mlx);
	return (_meta);
}
