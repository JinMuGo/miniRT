/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:18:25 by jgo               #+#    #+#             */
/*   Updated: 2023/06/21 13:54:22 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs_bonus.h"
#include "minirt_bonus.h"
#include "utils_bonus.h"
#include "render_bonus.h"
#include "light_bonus.h"

static inline t_rgba	_calc_pixel(
	t_meta *meta, const double u, const double v)
{
	const t_ray		ray = ray_from_camera(&meta->camera, u, v);
	t_record		record;

	record.t = 0;
	if (find_obj_in_pixel(meta->objs, (t_ray *)&ray, &record))
		return (phong_lighting(meta, &record, &ray));
	return (rgba_init_int(42, 42, 42, 255));
}

static inline t_rgba	_multi_sampling(t_meta *meta, const int x, const int y)
{
	const t_canvas	canvas = meta->scene.canvas;
	t_rgba			rgba;
	int				i;

	i = -1;
	rgba = rgba_init_int(0, 0, 0, 255);
	while (++i < SAMPLES_PER_PIXEL)
	{
		rgba = rgba_plus(rgba, \
				_calc_pixel(meta, \
				(x + ft_random_double()) / (canvas.width - 1), \
				(y + ft_random_double()) / (canvas.height -1)));
	}
	rgba = rgba_scalar_divide(rgba, SAMPLES_PER_PIXEL);
	return (rgba);
}

void	*render(void *args)
{
	t_renderer		*renderer;
	int				scene[2];

	renderer = args;
	scene[Y] = renderer->y;
	while (scene[Y] < renderer->height)
	{
		scene[X] = renderer->x;
		while (scene[X] < renderer->width)
		{
			mlx_put_pixel(renderer->meta->mlx_assets.img, scene[X], scene[Y],
				rgba_to_color(_multi_sampling(renderer->meta, scene[X], scene[Y])));
			scene[X]++;
		}
		scene[Y]++;
	}
	return (NULL);
}
