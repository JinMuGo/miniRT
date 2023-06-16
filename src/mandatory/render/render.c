/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:18:25 by jgo               #+#    #+#             */
/*   Updated: 2023/06/16 10:59:28 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"
#include "utils.h"
#include "render.h"
#include "light.h"

static inline t_rgba	_calc_pixel(t_meta* meta, int x, int y)
{
	const t_canvas	canvas = meta->scene.canvas;
	const double	ratio[2] = {(double)x / (canvas.width - 1), (double)y / (canvas.height - 1)};
	const t_ray		ray = ray_from_camera(&meta->camera, ratio);
	t_record		record;

	record.t = 0;
	if (find_obj_in_pixel(meta->objs, (t_ray *)&ray, &record))
		return (phong_lighting(meta, &record));
	return (rgba_init_int(42, 42, 42, 255));
}

//render-> obj -> each_funcion -> render(color)
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
				rgba_to_color(_calc_pixel(meta, canvas[X], canvas[Y])));
			canvas[X]++;
		}
		canvas[Y]++;
	}
}

