/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:38:15 by jgo               #+#    #+#             */
/*   Updated: 2023/07/13 21:32:29 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "defs_bonus.h"
#include "utils_bonus.h"

int	destroy(t_meta *meta)
{
	mlx_destroy_image(meta->mlx_assets.mlx, meta->mlx_assets.img.img);
	mlx_destroy_window(meta->mlx_assets.mlx, meta->mlx_assets.win);
	mlx_del(meta->mlx_assets.mlx);
	ft_lstclear(&meta->spot_lights, free);
	objs_clear(&meta->objs, free);
	free(meta->thd_pool.rendrer);
	free(meta->thd_pool.tids);
	free(meta);
	exit(EXIT_SUCCESS);
}
