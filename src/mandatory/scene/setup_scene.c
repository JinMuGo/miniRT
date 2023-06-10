/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:25:54 by jgo               #+#    #+#             */
/*   Updated: 2023/06/10 09:53:29 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"
#include "utils.h"

static inline void	_setup_canvas(t_canvas *canvas)
{
	canvas->width = WIN_WIDTH;
	canvas->height = WIN_HEIGHT;
	canvas->aspect_ratio = (double)WIN_HEIGHT / (double)WIN_WIDTH;
}

static inline void	_setup_camera(t_camera *camera)
{
	camera->pitch = 0;
	camera->yaw = 0;
	camera->front = vec3_init(0, -1, 0);
	camera->pos = vec3_init(0, 0, 3);
	camera->up = vec3_init(0, 1, 0);
}

static inline void	_render_background(t_meta *meta)
{
	int	axis[2];

	axis[Y] = 0;
	while (axis[Y] < WIN_HEIGHT)
	{
		axis[X] = 0;
		while (axis[X] < WIN_WIDTH)
		{
			mlx_put_pixel(meta->mlx_assets.img, axis[X], axis[Y],
				rgba_to_color(meta->ambient.rgba));
			axis[X]++;
		}
		axis[Y]++;
	}
}

void	setup_scene(t_meta *meta)
{
	_setup_canvas(&meta->scene.canvas);
	_setup_camera(&meta->scene.camera);
	_render_background(meta);
}
