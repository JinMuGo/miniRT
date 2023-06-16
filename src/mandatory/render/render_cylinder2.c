/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cylinder2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:10:28 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/16 19:15:37 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "render.h"

void	get_cylinder_coeff(t_cylinder *cy, t_ray *ray, double *coeff)
{
	const t_vec3	c_to_o = vec3_minus(ray->origin, cy->center_point);
	const double	a = vec3_inner_product(vec3_minus(ray->direction,
				vec3_scalar_multi(cy->normal_vec3,
					vec3_inner_product(ray->direction, cy->normal_vec3))),
			vec3_minus(ray->direction, vec3_scalar_multi(cy->normal_vec3,
					vec3_inner_product(ray->direction, cy->normal_vec3))));
	const double	b = 2.0 * vec3_inner_product(vec3_minus(ray->direction,
				vec3_scalar_multi(cy->normal_vec3,
					vec3_inner_product(ray->direction, cy->normal_vec3))),
			vec3_minus(c_to_o, vec3_scalar_multi(cy->normal_vec3,
					vec3_inner_product(c_to_o, cy->normal_vec3))));
	const double	c = vec3_inner_product(vec3_minus(c_to_o,
				vec3_scalar_multi(cy->normal_vec3,
					vec3_inner_product(c_to_o, cy->normal_vec3))),
			vec3_minus(c_to_o, vec3_scalar_multi(cy->normal_vec3,
					vec3_inner_product(c_to_o, cy->normal_vec3)))) \
	- ((cy->diameter / 2.0) * (cy->diameter / 2.0));

	coeff[A] = a;
	coeff[B] = b;
	coeff[C] = c;
}

void	get_top_bot_t(t_cylinder *cy, t_ray *ray, double *cap_inter)
{
	const double	top_t = vec3_inner_product(\
	vec3_minus(vec3_plus(cy->center_point, \
	vec3_scalar_multi(cy->normal_vec3, cy->height / 2)), ray->origin), \
	cy->normal_vec3) / vec3_inner_product(ray->direction, cy->normal_vec3);
	const double	bottom_t = vec3_inner_product(\
	vec3_minus(vec3_minus(cy->center_point, \
	vec3_scalar_multi(cy->normal_vec3, cy->height / 2)), ray->origin), \
	vec3_scalar_multi(cy->normal_vec3, -1)) \
	/ vec3_inner_product(ray->direction, \
	vec3_scalar_multi(cy->normal_vec3, -1));

	cap_inter[TOP] = top_t;
	cap_inter[BOT] = bottom_t;
}

bool	is_valid_height(double t, t_cylinder *cy, t_ray *ray)
{
	const t_vec3	intersect_point = ray_at(ray, t);
	const t_vec3	vec_to_center = vec3_minus(intersect_point,
			cy->center_point);
	const double	projected_length = vec3_inner_product(vec_to_center,
			cy->normal_vec3);
	double			res;

	if (t < 0)
		return (false);
	res = fabs(projected_length);
	if (res == 0)
		return (false);
	else
		return (fabs(projected_length) <= cy->height / 2.0);
}

bool	is_valid_cap(
		double t, const t_cylinder *cy, const t_ray *ray, t_cy_type type)
{
	t_vec3	cap_center;
	t_vec3	t_to_q;
	double	dot;
	double	len;

	if (type == TOP)
		cap_center = vec3_plus(cy->center_point,
				vec3_scalar_multi(cy->normal_vec3, cy->height / 2));
	else
		cap_center = vec3_minus(cy->center_point,
				vec3_scalar_multi(cy->normal_vec3, cy->height / 2));
	t_to_q = vec3_minus(ray_at((t_ray *)ray, t), cap_center);
	dot = vec3_inner_product(t_to_q, cy->normal_vec3);
	if (dot != 0)
		return (false);
	len = vec3_length(vec3_minus(cap_center, ray_at((t_ray *)ray, t)));
	if (dot == 0 && len >= 0 && len <= cy->diameter / 2)
		return (true);
	return (false);
}
