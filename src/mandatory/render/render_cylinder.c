/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:34 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/14 20:55:43 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "render.h"

static double	calculate_infinite_cylinder_t(t_cylinder cy, t_ray *ray)
{
	const t_vec3	c_to_o = vec3_minus(ray->origin, cy.center_point);
	const double	a = vec3_inner_product(vec3_minus(ray->direction,
				vec3_scalar_multi(cy.normal_vec3,
					vec3_inner_product(ray->direction, cy.normal_vec3))),
			vec3_minus(ray->direction,
				vec3_scalar_multi(cy.normal_vec3,
					vec3_inner_product(ray->direction, cy.normal_vec3))));
	const double	b = 2.0 * vec3_inner_product(vec3_minus(ray->direction,
				vec3_scalar_multi(cy.normal_vec3,
					vec3_inner_product(ray->direction, cy.normal_vec3))),
			vec3_minus(c_to_o, vec3_scalar_multi(cy.normal_vec3,
					vec3_inner_product(c_to_o, cy.normal_vec3))));
	const double	c = ((cy.diameter / 2) * (cy.diameter / 2)) * vec3_inner_product(vec3_minus(c_to_o, vec3_scalar_multi(cy.normal_vec3, vec3_inner_product(c_to_o, cy.normal_vec3))), vec3_minus(c_to_o, vec3_scalar_multi(cy.normal_vec3, vec3_inner_product(c_to_o, cy.normal_vec3))));
	double			root[2];

	if (root_formula(a, b, c, root) == false)
		return (0);
	if (root[0] > 0)
		return (root[0]);
	if (root[1] > 0)
		return (root[1]);
	return (0);
}

double	get_cylinder_dist(t_obj *obj, const t_ray *ray)
{
	const t_cylinder	cylinder = obj->content.cylinder;
	double				t;

	t = calculate_infinite_cylinder_t(cylinder, (t_ray *)ray);
	printf("t : %f\n", t);
	return (t);
}

t_object_type	get_cylinder_record(t_obj *obj, t_ray *ray, t_record *record)
{
	const t_cylinder	cylinder = obj->content.cylinder;
	t_vec3				projected_point;

	record->obj = &obj->content;
	record->point = ray_at(ray, record->t);
	projected_point = vec3_plus(cylinder.center_point, vec3_scalar_multi(cylinder.normal_vec3, vec3_inner_product(vec3_minus(record->point, cylinder.normal_vec3), cylinder.normal_vec3)));
	record->normal_vec3 = vec3_unit(vec3_minus(record->point, projected_point));
	set_face_normal(ray, record);
	return (obj->type);
}

t_rgba	get_cylinder_color(union u_obj *obj)
{
	const t_cylinder	cylinder = obj->cylinder;

	return (cylinder.rgba);
}
