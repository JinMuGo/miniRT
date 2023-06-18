/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:18:52 by jgo               #+#    #+#             */
/*   Updated: 2023/06/18 17:51:10 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"

static inline void	_update_camera_forward(
	t_camera *camera, const double pitch, const double yaw)
{
	const double	pitch_rad = degree_to_radian(pitch);
	const double	yaw_rad = degree_to_radian(yaw);
	const t_vec3	vec3 = vec3_init(cos(yaw_rad) * cos(pitch_rad),
			sin(pitch_rad),
			sin(yaw_rad) * cos(pitch_rad));

	camera->forward = vec3;
}

void	camera_cursor_hooks(const double pos[2], t_meta *meta)
{
	const double	camera_speed = 0.12;

	meta->camera.yaw -= (pos[X] - meta->hooks.prev_pos[X]) * camera_speed;
	meta->camera.pitch -= (pos[Y] - meta->hooks.prev_pos[Y]) * camera_speed;
	if (meta->camera.yaw < 0.0f)
		meta->camera.yaw += 180.0f;
	if (meta->camera.yaw > 360.0f)
		meta->camera.yaw -= 180.0f;
	if (meta->camera.pitch > 89.0f)
		meta->camera.pitch = 45.0f;
	if (meta->camera.pitch < -89.0f)
		meta->camera.pitch = -45.0f;
	_update_camera_forward(&meta->camera, meta->camera.pitch, meta->camera.yaw);
	meta->hooks.prev_pos[X] = pos[X];
	meta->hooks.prev_pos[Y] = pos[Y];
}

void	camera_key_hooks(mlx_key_data_t keydata, t_meta *meta)
{
	const double	camera_speed = 0.05;
	t_camera		*camera;

	camera = &meta->camera;
	if (keydata.key == MLX_KEY_W)
		camera->pos = vec3_minus(
				camera->pos, vec3_scalar_multi(camera->forward, camera_speed));
	if (keydata.key == MLX_KEY_S)
		camera->pos = vec3_plus(
				camera->pos, vec3_scalar_multi(camera->forward, camera_speed));
	if (keydata.key == MLX_KEY_D)
		camera->pos = vec3_plus(
				camera->pos, vec3_scalar_multi(camera->right, camera_speed));
	if (keydata.key == MLX_KEY_A)
		camera->pos = vec3_minus(
				camera->pos, vec3_scalar_multi(camera->right, camera_speed));
	if (keydata.key == MLX_KEY_E)
		camera->pos = vec3_minus(
				camera->pos, vec3_scalar_multi(camera->up, camera_speed));
	if (keydata.key == MLX_KEY_Q)
		camera->pos = vec3_plus(
				camera->pos, vec3_scalar_multi(camera->up, camera_speed));
}
