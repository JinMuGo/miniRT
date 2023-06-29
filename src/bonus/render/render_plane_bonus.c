/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_plane_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:43:23 by jgo               #+#    #+#             */
/*   Updated: 2023/06/29 14:25:38 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "defs_bonus.h"
#include "render_bonus.h"
#include "utils_bonus.h"

double	get_plane_dist(t_obj *obj, const t_ray *ray)
{
	const t_plane	plane = obj->content.plane;
	const t_vec3	pc = vec3_minus(ray->origin, plane.point);
	const double	denom = vec3_inner_product(\
								plane.normal_vec3, ray->direction);
	const double	numer = -1.0 * vec3_inner_product(plane.normal_vec3, pc);
	double			t;

	if (denom == 0 || fabs(denom) < EPSILON)
		return (0);
	t = numer * (1.0 / denom);
	if (t < 0)
		return (0);
	return (t);
}

static inline void	_set_plane_uv(t_obj_option *option, t_record *record)
{
	const double	u = fmod(\
				vec3_inner_product(option->op.tx.right, record->point), 1);
	const double	v = fmod(\
				vec3_inner_product(option->op.tx.up, record->point), 1);

	if (u < 0)
		option->op.tx.uv.u = u + 1.0;
	else
		option->op.tx.uv.u = u;
	if (v < 0)
		option->op.tx.uv.v = v + 1.0;
	else
		option->op.tx.uv.v = v;
}

t_object_type	get_plane_record(t_obj *obj, const t_ray *ray, t_record *record)
{
	const t_plane	plane = obj->content.plane;

	record->obj = obj;
	record->point = ray_at(ray, record->t);
	record->normal_vec3 = plane.normal_vec3;
	set_face_normal(ray, record);
	if (obj->option)
	{
		set_ab_axis_from_c(\
			&obj->option->op.tx.right,
			&obj->option->op.tx.up,
			&record->normal_vec3);
		_set_plane_uv(obj->option, record);
		apply_option(obj->option, record, plane.rgb);
	}
	else
		record->rgb = plane.rgb;
	return (obj->type);
}
