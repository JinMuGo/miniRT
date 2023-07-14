/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:16:51 by jgo               #+#    #+#             */
/*   Updated: 2023/07/14 11:07:06 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "defs_bonus.h"
#include "design_patterns_bonus.h"
#include "hooks_bonus.h"
#include "render_bonus.h"
#include "scene_bonus.h"
#include "thread_bonus.h"

t_vec3	*get_init_forward_pos(void)
{
	static t_vec3	_init_forward_pos[2];
	static bool		_initialized = false;
	t_meta			*meta;

	if (_initialized == false)
	{
		meta = singleton();
		_init_forward_pos[0] = meta->camera.forward;
		_init_forward_pos[1] = meta->camera.pos;
		_initialized = true;
	}
	return (_init_forward_pos);
}

int	mouse_move(int xpos, int ypos, t_meta *meta)
{
	const int	pos[2] = {xpos, ypos};

	if (meta->hooks.mouse_left == false)
		return (0);
	camera_mouse_hooks(pos, meta);
	return (0);
}
