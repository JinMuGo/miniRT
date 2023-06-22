/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:43:23 by jgo               #+#    #+#             */
/*   Updated: 2023/06/22 16:04:33 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "render.h"
#include "utils.h"

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

t_object_type	get_plane_record(t_obj *obj, t_ray *ray, t_record *record)
{
	const t_plane	plane = obj->content.plane;

	record->obj = obj;
	record->point = ray_at(ray, record->t);
	record->normal_vec3 = plane.normal_vec3;
	set_face_normal(ray, record);
	if (obj->option)
	{
		if (obj->option->type == CB)
			record->rgba = get_cb_color(plane.rgba, obj->option,&record->point);
	}
	else
		record->rgba = plane.rgba;
	return (obj->type);
}
