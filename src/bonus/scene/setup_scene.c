/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:25:54 by jgo               #+#    #+#             */
/*   Updated: 2023/06/20 20:19:24 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "utils.h"

static inline void	_setup_canvas(t_canvas *canvas, int width, int height)
{
	canvas->width = width;
	canvas->height = height;
	canvas->aspect_ratio = (double)height / (double)width;
}

static inline t_vec3	_camera_judge_up_vector(t_camera *camera)
{
	if (is_vec3_same(camera->forward, vec3_init(0, 1, 0)))
		return (vec3_init(0, 0, 1));
	if (is_vec3_same(camera->forward, vec3_init(0, -1, 0)))
		return (vec3_init(0, 0, -1));
	return (vec3_init(0, 1, 0));
}

static inline void	_setup_camera(t_camera *camera, double aspect_ratio)
{
	const t_vec3	tmp = _camera_judge_up_vector(camera);

	camera->right = vec3_unit(vec3_cross_product(tmp, camera->forward));
	camera->up = vec3_unit(vec3_cross_product(camera->forward, camera->right));
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

static inline	_setup_thread_pool(t_meta *meta)
{
	const int	height_n = meta->scene.canvas.height / THD_NUM;
	static bool	initialized = false;
	int			i;

	if (initialized == false)
	{
		meta->thd_pool.tids = ft_malloc(sizeof(pthread_t) * THD_NUM);
		meta->thd_pool.rendrer = ft_malloc(sizeof(t_renderer) * THD_NUM);
		initialized = true;
	}
	i = -1;
	while (++i < THD_NUM)
	{
		meta->thd_pool.rendrer[i].x = 0;
		meta->thd_pool.rendrer[i].y = i * height_n;
		meta->thd_pool.rendrer[i].width = meta->scene.canvas.width;
		meta->thd_pool.rendrer[i].height = (i + 1) * height_n;
		meta->thd_pool.rendrer[i].meta = meta;
	}
}

void	setup_scene(t_meta *meta, int width, int height)
{
	_setup_canvas(&meta->scene.canvas, width, height);
	_setup_camera(&meta->camera, meta->scene.canvas.aspect_ratio);
	_setup_thread_pool(meta);
}
