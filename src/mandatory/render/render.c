/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:18:25 by jgo               #+#    #+#             */
/*   Updated: 2023/06/18 15:39:58 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"
#include "utils.h"
#include "render.h"
#include "light.h"

static inline t_rgba	_calc_pixel(t_meta* meta, const double u, const double v)
{
	const t_ray		ray = ray_from_camera(&meta->camera, u, v);
	t_record		record;

	record.t = 0;
	if (find_obj_in_pixel(meta->objs, (t_ray *)&ray, &record))
		return (phong_lighting(meta, &record));
	return (rgba_init_int(42, 42, 42, 255));
}

static inline t_rgba	_multi_sampling(t_meta* meta, const int x, const int y)
{
	const t_canvas	canvas = meta->scene.canvas;
	t_rgba	rgba;
	int i;

	i = -1;
	rgba = rgba_init_int(0, 0, 0, 255);
	while (++i < SAMPLES_PER_PIXEL)
	{
		rgba = rgba_plus(rgba, _calc_pixel(meta, (x + ft_random_double()) / (canvas.width - 1), (y + ft_random_double()) / (canvas.height -1)));
	}
	rgba = rgba_scalar_divide(rgba, SAMPLES_PER_PIXEL);
	return (rgba);
}

void	render(t_meta *meta)
{
	const t_canvas _canvas = meta->scene.canvas;
	int canvas[2];

	canvas[Y] = 0;
	while (canvas[Y] < _canvas.height)
	{
		canvas[X] = 0;
		while (canvas[X] < _canvas.width)
		{
			mlx_put_pixel(meta->mlx_assets.img, canvas[X], canvas[Y],
				rgba_to_color(_multi_sampling(meta, canvas[X], canvas[Y])));
			canvas[X]++;
		}
		canvas[Y]++;
	}
	mlx_image_to_window(meta->mlx_assets.mlx, meta->mlx_assets.img, 0, 0);
}

