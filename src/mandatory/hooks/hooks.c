/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:08:41 by jgo               #+#    #+#             */
/*   Updated: 2023/07/14 11:18:04 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "hooks.h"
#include "minirt.h"
#include "render.h"
#include "scene.h"
#include "utils.h"

static inline int	_key_press(int keydata, t_meta *meta)
{
	if (keydata == MLX_KEY_ESC)
		destroy(meta);
	camera_key_hooks(keydata, meta);
	return (0);
}

static inline int	_key_release(int keydata, t_meta *meta)
{
	const t_vec3	*init_forward_pos = get_init_forward_pos();

	if (keydata == MLX_KEY_ESC)
		destroy(meta);
	if (keydata == MLX_KEY_R)
		meta->camera.forward = init_forward_pos[0];
	if (keydata == MLX_KEY_F)
		meta->camera.pos = init_forward_pos[1];
	if ((MLX_KEY_Q <= keydata && keydata <= MLX_KEY_R) || (MLX_KEY_A <= keydata
			&& keydata <= MLX_KEY_F) || (MLX_KEY_Z <= keydata
			&& keydata <= MLX_KEY_C))
	{
		setup_scene(meta, meta->scene.canvas.width, meta->scene.canvas.height);
		render(meta);
	}
	return (0);
}

static inline int	_mouse_press(
	int button, int x, int y, t_meta *meta)
{
	(void)x;
	(void)y;
	if (button == 1 && meta->hooks.mouse_left == false)
		meta->hooks.mouse_left = true;
	if (button == 2 && meta->hooks.mouse_right == false)
		meta->hooks.mouse_right = true;
	return (0);
}

static inline int	_mouse_release(
	int button, int x, int y, t_meta *meta)
{
	(void)x;
	(void)y;
	if (button == 1 && meta->hooks.mouse_left == true)
		meta->hooks.mouse_left = false;
	if (button == 2 && meta->hooks.mouse_right == true)
		meta->hooks.mouse_right = false;
	setup_scene(meta, meta->scene.canvas.width, meta->scene.canvas.height);
	render(meta);
	return (0);
}

void	hooks(t_meta *meta)
{
	get_init_forward_pos();
	mlx_hook(meta->mlx_assets.win, KEY_PRESS, 0, _key_press, meta);
	mlx_hook(meta->mlx_assets.win, KEY_RELEASE, 0, _key_release, meta);
	mlx_hook(meta->mlx_assets.win, MOUSE_PRESS, 0, _mouse_press, meta);
	mlx_hook(meta->mlx_assets.win, MOUSE_RELEASE, 0, _mouse_release, meta);
	mlx_hook(meta->mlx_assets.win, MOTION_NOTIFY, 0, mouse_move, meta);
	mlx_hook(meta->mlx_assets.win, DESTROY_NOTIFY, 0, destroy, meta);
}
