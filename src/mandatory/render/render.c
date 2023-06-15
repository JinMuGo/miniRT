/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:18:25 by jgo               #+#    #+#             */
/*   Updated: 2023/06/15 09:25:34 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"
#include "utils.h"
#include "render.h"

static inline t_get_obj_color	__obj_color_func_classifier(t_object_type type)
{
	if (type == SP)
		return (get_sphere_color);
	if (type == PL)
		return (get_plane_color);
	if (type == CY)
		return (get_cylinder_color);
	return (NULL);
}

static inline int32_t	_calc_pixel(t_meta* meta, int x, int y)
{
	const double	ratio[2] = {(double)x / (WIN_WIDTH - 1), (double)y / (WIN_HEIGHT - 1)};
	const t_ray		ray = ray_init(&meta->camera, ratio);
	t_record		record;

	if (find_obj_in_pixel(meta->objs, &ray, &record) == false)
		return (rgba_to_color(rgba_init(42, 42, 42, 255)));
	record.rgba = __obj_color_func_classifier(record.obj->type)(&record.obj->content, meta);
	// + lighting
	//calc_light();
	return (rgba_to_color(record.rgba));
}

//render-> obj -> each_funcion -> render(color)
void	render(t_meta *meta)
{
	int canvas[2];

	canvas[Y] = 0;
	while (canvas[Y] < WIN_HEIGHT)
	{
		canvas[X] = 0;
		while (canvas[X] < WIN_WIDTH)
		{
			mlx_put_pixel(meta->mlx_assets.img, canvas[X], canvas[Y],
				_calc_pixel(meta, canvas[X], canvas[Y]));
			canvas[X]++;
		}
		canvas[Y]++;
	}
}

