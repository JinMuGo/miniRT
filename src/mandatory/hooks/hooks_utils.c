/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:16:51 by jgo               #+#    #+#             */
/*   Updated: 2023/07/10 14:14:54 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "design_patterns.h"

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
