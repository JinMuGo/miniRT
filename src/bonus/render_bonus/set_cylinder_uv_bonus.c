/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cylinder_uv_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:55:48 by jgo               #+#    #+#             */
/*   Updated: 2023/06/29 15:49:35 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "defs_bonus.h"

static inline void	_set_cylinder_tube_uv(
	t_obj_option *option, t_record *record, const t_cylinder *cylinder)
{
	const t_point3	center_of_disk = vec3_plus(\
		cylinder->center_point, \
		vec3_scalar_multi(cylinder->normal_vec3, cylinder->height / 2));
	const t_vec3	r_reverse = vec3_scalar_multi(option->op.tx.right, -1);
	const t_vec3	p_to_c = vec3_minus(record->point, center_of_disk);
	const double	t = vec3_inner_product(p_to_c, cylinder->normal_vec3) / \
		vec3_inner_product(cylinder->normal_vec3, cylinder->normal_vec3);

	if (vec3_inner_product(option->op.tx.right, record->normal_vec3) > 0)
		option->op.tx.uv.u = acos(\
			vec3_inner_product(\
				option->op.tx.right, record->normal_vec3)) / (2 * M_PI);
	else
		option->op.tx.uv.u = (M_PI + acos(\
			vec3_inner_product(\
				r_reverse, record->normal_vec3))) / (2 * M_PI);
	option->op.tx.uv.v = -t / cylinder->height;
}

static inline void	_set_cylinder_cap_uv(
	t_obj_option *option, t_record *record, const t_cylinder *cylinder)
{
	const double	u = fmod(\
		vec3_inner_product(\
			option->op.tx.right, record->point) / cylinder->diameter, 1);
	const double	v = fmod(\
		vec3_inner_product(\
			option->op.tx.up, record->point) / cylinder->diameter, 1);

	if (u < 0)
		option->op.tx.uv.u = u + 1.0;
	else
		option->op.tx.uv.u = u;
	if (v < 0)
		option->op.tx.uv.v = v + 1.0;
	else
		option->op.tx.uv.v = v;
}

void	set_cylinder_uv(
	t_obj_option *option, t_record *record, const t_cylinder *cylinder)
{
	if (cylinder->p_type == TUBE)
	{
		set_ab_axis_from_c(
			&option->op.tx.right, &option->op.tx.up, &cylinder->normal_vec3);
		_set_cylinder_tube_uv(option, record, cylinder);
	}
	else
	{
		set_ab_axis_from_c(
			&option->op.tx.right, &option->op.tx.up, &record->normal_vec3);
		_set_cylinder_cap_uv(option, record, cylinder);
	}
}
