/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:18:52 by jgo               #+#    #+#             */
/*   Updated: 2023/06/17 17:40:03 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"

void __update_camera_forward(t_camera *camera, double pitch, double yaw)
{
    double pitch_rad = degree_to_radian(pitch);
    double yaw_rad = degree_to_radian(yaw);
    double forward_x = cos(yaw_rad) * cos(pitch_rad);
    double forward_y = sin(pitch_rad);
    double forward_z = sin(yaw_rad) * cos(pitch_rad);

    // 업데이트된 forward 벡터를 적용
    camera->forward = vec3_init(forward_x, forward_y, forward_z);
    camera->forward = vec3_unit(camera->forward);
}

void	camera_key_hooks(mlx_key_data_t keydata, t_meta *meta)
{
	const double	camera_speed = 0.05;
	t_camera *camera;

	camera = &meta->camera;
	if (keydata.key == MLX_KEY_W)
		camera->pos = vec3_minus(camera->pos,vec3_scalar_multi(camera->forward, camera_speed));
	if (keydata.key == MLX_KEY_S)
		camera->pos = vec3_plus(camera->pos,vec3_scalar_multi(camera->forward, camera_speed));
	if (keydata.key == MLX_KEY_D)
		camera->pos = vec3_plus(camera->pos,vec3_scalar_multi(camera->right, camera_speed));
	if (keydata.key == MLX_KEY_A)
		camera->pos = vec3_minus(camera->pos,vec3_scalar_multi(camera->right, camera_speed));
	if (keydata.key == MLX_KEY_E)
		camera->pos = vec3_minus(camera->pos,vec3_scalar_multi(camera->up, camera_speed));
	if (keydata.key == MLX_KEY_Q)
		camera->pos = vec3_plus(camera->pos,vec3_scalar_multi(camera->up, camera_speed));
}

void	camera_cursor_hooks(const double pos[2], t_meta* meta)
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
	__update_camera_forward(&meta->camera, meta->camera.pitch, meta->camera.yaw);
	meta->hooks.prev_pos[X] = pos[X];
	meta->hooks.prev_pos[Y] = pos[Y];
}
