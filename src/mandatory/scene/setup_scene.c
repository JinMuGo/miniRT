/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:25:54 by jgo               #+#    #+#             */
/*   Updated: 2023/06/16 17:25:42 by sanghwal         ###   ########seoul.kr  */
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
	camera->normal_vec3 = vec3_unit(camera->normal_vec3);
	camera->front = camera->normal_vec3;
	camera->pos = camera->view_point;
	camera->up = vec3_init(0, 1, 0);
	camera->z = vec3_scalar_multi(camera->normal_vec3, -1);
	camera->x = vec3_unit(vec3_cross_product(camera->up, camera->z));
	camera->y = vec3_unit(vec3_cross_product(camera->z, camera->x));
	camera->viewport_w = tan(degree_to_radian(camera->fov) / 2) * FOCAL_LENGTH
		* 2;
	camera->viewport_h = camera->viewport_w * aspect_ratio;
	camera->horizontal = vec3_scalar_multi(camera->x, camera->viewport_w);
	camera->vertical = vec3_scalar_multi(camera->y, camera->viewport_h);
	camera->left_bottom = vec3_minus(camera->pos, vec3_plus(vec3_plus(vec3_scalar_multi(camera->x, camera->viewport_w / 2), vec3_scalar_multi(camera->y, camera->viewport_h / 2)), camera->z));
}

void	setup_scene(t_meta *meta)
{
	_setup_canvas(&meta->scene.canvas);
	_setup_camera(&meta->camera, meta->scene.canvas.aspect_ratio);
}
