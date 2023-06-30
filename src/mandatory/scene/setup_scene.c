/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:25:54 by jgo               #+#    #+#             */
/*   Updated: 2023/06/30 10:19:38 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"
#include "utils.h"

static inline void	_setup_canvas(t_canvas *canvas, int width, int height)
{
	canvas->width = width;
	canvas->height = height;
	canvas->aspect_ratio = (double)height / (double)width;
}

static inline void	_setup_camera(t_camera *camera, double aspect_ratio)
{
	set_ab_axis_from_c(&camera->right, &camera->up, &camera->forward);
	camera->viewport_w = tan(degree_to_radian(camera->fov) / 2) * FOCAL_LENGTH
		* 2;
	camera->viewport_h = camera->viewport_w * aspect_ratio;
	camera->horizontal = vec3_scalar_multi(camera->right, camera->viewport_w);
	camera->vertical = vec3_scalar_multi(camera->up, camera->viewport_h);
	camera->left_bottom = vec3_minus(camera->pos, \
		vec3_plus(vec3_plus(\
			vec3_scalar_multi(camera->right, camera->viewport_w / 2), \
			vec3_scalar_multi(camera->up, camera->viewport_h / 2)), \
			camera->forward));
}

void	setup_scene(t_meta *meta, int width, int height)
{
	_setup_canvas(&meta->scene.canvas, width, height);
	_setup_camera(&meta->camera, meta->scene.canvas.aspect_ratio);
}
