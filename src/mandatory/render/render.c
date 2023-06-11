/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:18:25 by jgo               #+#    #+#             */
/*   Updated: 2023/06/11 18:31:59 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"
#include "utils.h"
#include "render.h"

static inline	void	calc_light()
{

}

static inline int32_t	_calc_pixel(t_meta* meta, int x, int y)
{
	const double	ratio[2] = {x / (WIN_WIDTH - 1), y / (WIN_HEIGHT - 1)};
	const t_ray		ray = ray_init(&meta->camera, ratio);
	t_record		record;

	if (find_obj_in_pixel(meta->objs, &ray, &record) == false)
		return (rgba_to_color(rgba_init(42, 42, 42, 255)));
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

