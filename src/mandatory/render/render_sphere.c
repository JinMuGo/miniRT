/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:18:31 by jgo               #+#    #+#             */
/*   Updated: 2023/06/12 14:56:19 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"

double get_sphere_dist(t_obj *obj, const t_ray *ray)
{
	const t_sphere	sphere = obj->content.sphere;
	const t_vec3	o_to_c = vec3_minus(ray->origin, sphere.center_point);
	const t_quad_assets ast = {
		vec3_square_length(ray->direction),
		vec3_inner_product(o_to_c, ray->direction),
		vec3_square_length(o_to_c) - (sphere.radius * sphere.radius)};
	const double	d = ast.half_b * ast.half_b - ast.a * ast.c;

	if (d < 0)
		return (0);
	return (fmin((-ast.half_b - sqrt(d)) / ast.a,(-ast.half_b + sqrt(d)) / ast.a));
}

t_rgba get_sphere_color(union u_obj *obj, const t_ray *ray, t_record *record)
{
	const t_sphere sphere = obj->sphere;

	return (sphere.rgba);
}
