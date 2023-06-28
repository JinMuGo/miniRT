/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cone2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:40:01 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/23 17:40:47 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "render.h"

void	get_cone_coeff(t_cone *cone, t_ray *ray, double *coeff)
{
	double	m;
	t_vec3	co;
	double	v_n_pow;
	double	v_n_dot_w_n;
	double	w_n_pow;

	co = vec3_minus(ray->origin, cone->base_point);
	m = cone->radius * cone->radius / (cone->height * cone->height);
	v_n_pow = vec3_inner_product(ray->direction, cone->normal_vec3) * \
			vec3_inner_product(ray->direction, cone->normal_vec3);
	v_n_dot_w_n = vec3_inner_product(ray->direction, cone->normal_vec3) * \
			vec3_inner_product(co, cone->normal_vec3);
	w_n_pow = vec3_inner_product(co, cone->normal_vec3) * \
			vec3_inner_product(co, cone->normal_vec3);
	coeff[A] = vec3_inner_product(ray->direction, ray->direction) - \
		((1 + m) * v_n_pow);
	coeff[B] = 2 * (vec3_inner_product(ray->direction, co) - \
		((1 + m) * v_n_dot_w_n) + (m * cone->height * \
			vec3_inner_product(ray->direction, cone->normal_vec3)));
	coeff[C] = vec3_inner_product(co, co) - ((1 + m) * w_n_pow) + \
		(2 * m * cone->height * vec3_inner_product(co, cone->normal_vec3)) - \
			cone->radius * cone->radius;
}

bool	is_within_cone_height(t_cone *cone, t_ray *ray, double root)
{
	const t_point3	intersection_point = vec3_plus(ray->origin, \
			vec3_scalar_multi(ray->direction, root));
	const t_vec3	base_to_intersect = vec3_minus(\
			intersection_point, cone->base_point);
	const double	proj_length = vec3_inner_product(base_to_intersect, \
			cone->normal_vec3);

	return (0 <= proj_length && proj_length <= cone->height);
}

bool	is_valid_base(double t, t_cone *cone, t_ray *ray)
{
	t_vec3	t_to_q;
	double	dot;
	double	len;

	t_to_q = vec3_minus(ray_at(ray, t), cone->base_point);
	dot = vec3_inner_product(t_to_q, cone->normal_vec3);
	len = vec3_length(t_to_q);
	if (fabs(dot) < EPSILON && len >= 0 && len <= cone->radius)
		return (true);
	return (false);
}
