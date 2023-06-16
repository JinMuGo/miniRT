/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:08:41 by jgo               #+#    #+#             */
/*   Updated: 2023/06/16 16:38:42 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"
#include "utils.h"
#include "scene.h"
#include "render.h"

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_meta	*meta;

	meta = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		destroy(meta);
}

void	resize_hook(int32_t width, int32_t height, void *param)
{
	t_meta *meta;

	meta = param;
	setup_scene(meta, width, height);
	render(meta);
}

void	hooks(t_meta *meta)
{
	mlx_resize_hook(meta->mlx_assets.mlx, resize_hook, meta);
	mlx_key_hook(meta->mlx_assets.mlx, key_hooks, meta);
}
