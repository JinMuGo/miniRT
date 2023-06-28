/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:31:18 by jgo               #+#    #+#             */
/*   Updated: 2023/06/06 18:20:58 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"

static inline void	_init_mlx_assets(t_mlx_assets *mlx_assets)
{
	mlx_assets->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "miniRT", true);
	mlx_assets->img = mlx_new_image(mlx_assets->mlx, WIN_WIDTH, WIN_HEIGHT);
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
