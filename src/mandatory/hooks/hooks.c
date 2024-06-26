/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:08:41 by jgo               #+#    #+#             */
/*   Updated: 2023/06/30 19:26:12 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "hooks.h"
#include "minirt.h"
#include "render.h"
#include "scene.h"
#include "utils.h"

static inline void	_key_hooks(mlx_key_data_t keydata, void *param)
{
	t_meta	*meta;

	meta = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		destroy(meta);
	camera_key_hooks(keydata, meta);
	if (keydata.action == MLX_RELEASE)
	{
		setup_scene(meta, meta->scene.canvas.width, meta->scene.canvas.height);
		render(meta);
	}
}

static inline void	_resize_hook(int32_t width, int32_t height, void *param)
{
	t_meta	*meta;

	meta = param;
	setup_scene(meta, width, height);
	render(meta);
}

static inline void	_mouse_hooks(
	mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_meta	*meta;

	(void)mods;
	meta = param;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS
		&& meta->hooks.mouse_left == false)
		meta->hooks.mouse_left = true;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_RELEASE
		&& meta->hooks.mouse_left == true)
		meta->hooks.mouse_left = false;
	if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_PRESS
		&& meta->hooks.mouse_right == false)
		meta->hooks.mouse_right = true;
	if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_RELEASE
		&& meta->hooks.mouse_right == true)
		meta->hooks.mouse_right = false;
}

static inline void	_mouse_cursor(double xpos, double ypos, void *param)
{
	const double	pos[2] = {xpos, ypos};
	t_meta			*meta;

	meta = param;
	if (meta->hooks.mouse_left == false)
		return ;
	camera_cursor_hooks(pos, meta);
	setup_scene(meta, meta->scene.canvas.width, meta->scene.canvas.height);
	render(meta);
}

void	hooks(t_meta *meta)
{
	mlx_resize_hook(meta->mlx_assets.mlx, _resize_hook, meta);
	mlx_key_hook(meta->mlx_assets.mlx, _key_hooks, meta);
	mlx_mouse_hook(meta->mlx_assets.mlx, _mouse_hooks, meta);
	mlx_cursor_hook(meta->mlx_assets.mlx, _mouse_cursor, meta);
}
