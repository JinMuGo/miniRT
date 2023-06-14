/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:43:23 by jgo               #+#    #+#             */
/*   Updated: 2023/06/14 14:25:11 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "render.h"

double	get_plane_dist(t_obj *obj, const t_ray *ray)
{
	const t_plane	plane = obj->content.plane;
	const t_vec3	pc = vec3_minus(ray->origin, plane.point);
	const double	denom = vec3_inner_product(plane.normal_vec3, ray->direction);
	const double	numer = -1.0 * vec3_inner_product(plane.normal_vec3, pc);
	double			t;

	if (denom == 0 || fabs(denom) < EPSILON)
		return (0);
	t = numer / denom;
	if (t < 0)
		return (0);
	return (t);
}

t_object_type	get_plane_record(t_obj *obj, t_ray *ray, t_record *record)
{
	const t_plane	plane = obj->content.plane;

	record->obj = &obj->content;
	record->point = ray_at(ray, record->t);
	record->normal_vec3 = plane.normal_vec3;
	set_face_normal(ray, record);
	return (obj->type);
}

t_rgba	get_plane_color(union u_obj *obj)
{
	const t_plane	plane = obj->plane;

	return (plane.rgba);
}
