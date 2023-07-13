/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:18:25 by jgo               #+#    #+#             */
/*   Updated: 2023/07/13 12:42:08 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"
#include "utils.h"
#include "render.h"
#include "light.h"

static inline t_rgb	_calc_pixel(
	t_meta *meta, const double u, const double v)
{
	const t_ray		ray = ray_from_camera(&meta->camera, u, v);
	t_record		record;

	record.t = 0;
	if (find_obj_in_pixel(meta->objs, &ray, &record))
		return (phong_lighting(meta, &record, &ray));
	return (rgba_init_int(42, 42, 42));
}

static inline t_rgb	_multi_sampling(t_meta *meta, const int x, const int y)
{
	const t_canvas	canvas = meta->scene.canvas;
	t_rgb			rgb;
	int				i;

	i = -1;
	rgb = rgba_init_int(0, 0, 0);
	while (++i < SAMPLES_PER_PIXEL)
	{
		rgb = vec3_plus(rgb, \
				_calc_pixel(meta, \
				(x + ft_random_double()) / (canvas.width - 1), \
				(y + ft_random_double()) / (canvas.height - 1)));
	}
	return (vec3_scalar_divide(rgb, SAMPLES_PER_PIXEL));
}

void	render(t_meta *meta)
{
	const t_canvas	_canvas = meta->scene.canvas;
	int				scene[2];

	scene[Y] = 0;
	while (scene[Y] < _canvas.height)
	{
		scene[X] = 0;
		while (scene[X] < _canvas.width)
		{
			my_pixel_put(&meta->mlx_assets, scene[X], scene[Y],
				rgba_to_color(_multi_sampling(meta, scene[X], scene[Y])));
			scene[X]++;
		}
		scene[Y]++;
	}
}
