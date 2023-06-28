/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:14:58 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/23 17:40:38 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "render.h"

static double	get_cone_side(t_cone *cone, t_ray *ray)
{
	double	coeff[3];
	double	root[2];

	get_cone_coeff(cone, ray, coeff);
	if (!root_formula(coeff[A], coeff[B], coeff[C], root))
		return (0);
	if (is_within_cone_height(cone, ray, root[0]))
		return (root[0]);
	if (is_within_cone_height(cone, ray, root[1]))
		return (root[1]);
	return (0);
}

static double	get_cone_base(t_cone *cone, t_ray *ray)
{
	const t_vec3	pc = vec3_minus(ray->origin, cone->base_point);
	const double	denom = vec3_inner_product(\
							cone->normal_vec3, ray->direction);
	const double	numer = -1.0 * vec3_inner_product(cone->normal_vec3, pc);
	double			t;

	if (fabs(denom) < EPSILON)
		return (0);
	t = numer / denom;
	if (t < 0)
		return (0);
	if (!is_valid_base(t, cone, ray))
		return (0);
	return (t);
}

double	get_cone_dist(t_obj *obj, const t_ray *ray)
{
	t_cone	*cone;
	double	side_t;
	double	base_t;

	cone = &(obj->content.cone);
	side_t = get_cone_side(cone, (t_ray *)ray);
	base_t = get_cone_base(cone, (t_ray *)ray);
	cone->co_type = SIDE;
	if ((side_t > 0 && base_t <= 0)
		|| (side_t > 0 && base_t > 0 && side_t <= base_t))
		return (side_t);
	else if (base_t > 0)
	{
		cone->co_type = BASE;
		return (base_t);
	}
	return (0);
}

static void	_get_side_normal_vec3(t_cone cone, t_record *record)
{
	const double	ac = cone.height - (vec3_square_length(vec3_minus(\
	vec3_minus(record->point, cone.base_point), \
	vec3_scalar_multi(cone.normal_vec3, cone.height))) / \
	(cone.height - vec3_inner_product(vec3_minus(record->point, \
	cone.base_point), cone.normal_vec3)));

	record->normal_vec3 = vec3_unit(vec3_minus(record->point, \
	vec3_plus(cone.base_point, vec3_scalar_multi(cone.normal_vec3, ac))));
}

t_object_type	get_cone_record(t_obj *obj, t_ray *ray, t_record *record)
{
	const t_cone	cone = obj->content.cone;

	record->obj = obj;
	record->point = ray_at(ray, record->t);
	if (cone.co_type == SIDE)
		_get_side_normal_vec3(cone, record);
	if (cone.co_type == BASE)
		record->normal_vec3 = vec3_scalar_multi(cone.normal_vec3, -1);
	set_face_normal(ray, record);
	record->rgba = cone.rgba;
	return (obj->type);
}
