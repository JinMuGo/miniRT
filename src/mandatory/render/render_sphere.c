/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:18:31 by jgo               #+#    #+#             */
/*   Updated: 2023/06/18 17:18:50 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "render.h"
#include "utils.h"
#include "light.h"

double	get_sphere_dist(t_obj *obj, const t_ray *ray)
{
	const t_sphere		sphere = obj->content.sphere;
	const t_vec3		c_to_o = vec3_minus(ray->origin, sphere.center_point);
	const t_quad_coeff	coeff = {
		vec3_square_length(ray->direction),
		vec3_inner_product(c_to_o, ray->direction) * 2.0,
		vec3_inner_product(c_to_o, c_to_o) - (sphere.radius * sphere.radius)};
	double				root[2];

	if (root_formula(coeff.a, coeff.b, coeff.c, root) == false)
		return (0);
	if (root[0] > 0)
		return (root[0]);
	if (root[1] > 0)
		return (root[1]);
	return (0);
}

t_object_type	get_sphere_record(t_obj *obj, t_ray *ray, t_record *record)
{
	const t_sphere	sphere = obj->content.sphere;

	record->obj = obj;
	record->point = ray_at(ray, record->t);
	record->normal_vec3 = vec3_scalar_divide(\
				vec3_minus(record->point, sphere.center_point), sphere.radius);
	set_face_normal(ray, record);
	record->rgba = sphere.rgba;
	return (obj->type);
}
