/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:18:25 by jgo               #+#    #+#             */
/*   Updated: 2023/06/10 21:18:59 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"
#include "utils.h"
#include "render.h"

static inline	void	calc_light()
{

}

static inline void	record_init(t_hit_record *record)
{
	record->t_min = 0;
	record->t_max = INFINITY;
}

static inline int32_t	calc_pixel(t_meta* meta, int x, int y)
{
	const double	ratio[2] = {x / (WIN_WIDTH - 1), y / (WIN_HEIGHT - 1)};
	const t_ray		ray = ray_init(&meta->camera, ratio);
	t_hit_record	record;

	record_init(&record);
	if (hit_obj(meta->objs, &ray, &record) == false)
		return (rgba_to_color(rgba_init(42, 42, 42, 255)));
	// + lighting
	//calc_light();
	return (rgba_to_color(record.rgba));
}

//render-> obj -> each_funcion -> render(color)
void	render(t_meta *meta)
{
	int canvas[2];

	// camera front 설정.
	//meta->camera.front =
	// camera 의 ray
	canvas[Y] = 0;
	while (canvas[Y] < WIN_HEIGHT)
	{
		canvas[X] = 0;
		while (canvas[X] < WIN_WIDTH)
		{
			mlx_put_pixel(meta->mlx_assets.img, canvas[X], canvas[Y],
				calc_pixel(meta, canvas[X], canvas[Y]));
			canvas[X]++;
		}
		axis[Y]++;
	}
}

