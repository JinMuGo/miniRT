/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sphere_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:18:31 by jgo               #+#    #+#             */
/*   Updated: 2023/06/30 13:43:40 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "defs_bonus.h"
#include "render_bonus.h"
#include "utils_bonus.h"
#include "light_bonus.h"

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

static inline void	_set_sphere_uv(t_obj_option *option, t_record *record)
{
	const double	phi = atan2(\
				-record->normal_vec3.z, record->normal_vec3.x) + M_PI;
	const double	theta = acos(-record->normal_vec3.y);

	option->op.tx.uv.u = phi / (M_PI * 2);
	option->op.tx.uv.v = theta / M_PI;
}

t_object_type	set_sphere_record(
	t_obj *obj, const t_ray *ray, t_record *record)
{
	const t_sphere	sphere = obj->content.sphere;

	record->point = ray_at(ray, record->t);
	record->normal_vec3 = vec3_scalar_divide(\
				vec3_minus(record->point, sphere.center_point), sphere.radius);
	set_face_normal(ray, record);
	if (obj->option)
	{
		if (obj->option->type == TX)
		{
			set_ab_axis_from_c(\
				&obj->option->op.tx.right,
				&obj->option->op.tx.up,
				&record->normal_vec3);
			_set_sphere_uv(obj->option, record);
		}
		apply_option(obj->option, record, sphere.rgb);
	}
	else
		record->rgb = sphere.rgb;
	return (obj->type);
}
