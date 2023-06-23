/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:03:21 by jgo               #+#    #+#             */
/*   Updated: 2023/06/22 16:06:47 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "utils.h"

t_rgba	get_cb_color(const t_rgba rgba, t_obj_option *option, t_point3 *point)
{
	const t_cb	cb = option->op.cb;
	const float	radian = degree_to_radian(cb.degree);
	const float	s = point->x * cos(radian) - point->y * sin(radian);
	const float	t = point->y * cos(radian) + point->x * sin(radian);
	const bool	pattern = (float_modulo(s * 1 / cb.scale_s) < 0.5) ^ (float_modulo(t * 1 / cb.scale_t) < 0.5);

	if (pattern)
		return (rgba);
	else
		return (cb.rgba);
}