/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:35:56 by jgo               #+#    #+#             */
/*   Updated: 2023/07/14 10:47:28 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs_bonus.h"
#include "minirt_bonus.h"
#include "render_bonus.h"
#include "utils_bonus.h"

void	start_thread_render(t_meta *meta)
{
	int	i;

	i = -1;
	while (++i < THD_NUM)
	{
		if (pthread_create(meta->thd_pool.tids + i, NULL, render,
				meta->thd_pool.rendrer + i))
			return (error_handler(THD_ERR));
	}
	i = -1;
	while (++i < THD_NUM)
		pthread_join(meta->thd_pool.tids[i], NULL);
	mlx_put_image_to_window(meta->mlx_assets.mlx, meta->mlx_assets.win,
		meta->mlx_assets.img.img, 0, 0);
	printf("finish thread render! with: %d threads\n", THD_NUM);
}
