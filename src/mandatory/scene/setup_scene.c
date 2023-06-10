/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:25:54 by jgo               #+#    #+#             */
/*   Updated: 2023/06/10 20:30:16 by jgo              ###   ########.fr       */
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

static inline void	_setup_camera(t_camera *camera, double aspect_ratio)
{
	camera->pitch = 0;
	camera->yaw = 0;
	camera->front = camera->normal_vec3;
	camera->pos = camera->view_point;
	camera->up = vec3_init(0, -1, 0);
	camera->viewport_w = tan(degree_to_radian(camera->fov) / 2) * FOCAL_LENGTH
		* 2;
	camera->viewport_h = camera->viewport_w * aspect_ratio;
	camera->horizontal = vec3_init(camera->viewport_w, 0, 0);
	camera->vertical = vec3_init(0, camera->viewport_h, 0);
	camera->left_bottom = vec3_minus(vec3_minus(vec3_minus(camera->pos,
				vec3_scalar_divide(camera->horizontal, 2)),
			vec3_scalar_divide(camera->vertical, 2)), vec3_init(0, 0,
			FOCAL_LENGTH));
}

static inline void	_render_background(t_meta *meta)
{
	const t_rgba	rgba_bgr = rgba_init(42, 42, 42, 255);
	int				axis[2];


	axis[Y] = 0;
	while (axis[Y] < WIN_HEIGHT)
	{
		axis[X] = 0;
		while (axis[X] < WIN_WIDTH)
		{
			mlx_put_pixel(meta->mlx_assets.img, axis[X], axis[Y],
				rgba_to_color(rgba_bgr));
			axis[X]++;
		}
		axis[Y]++;
	}
}

void	setup_scene(t_meta *meta)
{
	_setup_canvas(&meta->scene.canvas);
	_setup_camera(&meta->scene.camera, meta->scene.canvas.aspect_ratio);
	_render_background(meta);
}
