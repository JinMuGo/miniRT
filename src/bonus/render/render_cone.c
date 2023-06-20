/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:14:58 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/20 17:21:26 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "render.h"

double			get_cone_dist(t_obj *obj, const t_ray *ray);
t_object_type	get_cone_record(t_obj *obj, t_ray *ray, t_record *record);

double	get_cone_dist(t_obj *obj, const t_ray *ray)
{
	t_cone	cone;
	
	cone = obj->content.cone;
	t_vec3	CO = vec3_minus(cone.center_point, ray->origin);
	double cos_a = cone.radius / sqrt(cone.radius*cone.radius + cone.height*cone.height); // cos(α)
	double cos_a2 = cos_a * cos_a; // cos^2(α)
	double a = vec3_inner_product(ray->direction, ray->direction) * vec3_inner_product(ray->direction, ray->direction) - cos_a2 * vec3_inner_product(ray->direction, cone.normal_vec3) * vec3_inner_product(ray->direction, cone.normal_vec3);
	double b = 2 * (vec3_inner_product(ray->direction, CO) - cos_a2 * vec3_inner_product(ray->direction, cone.normal_vec3) * vec3_inner_product(CO, cone.normal_vec3));
	double c = vec3_inner_product(CO, CO) * vec3_inner_product(CO, CO) - cos_a2 * vec3_inner_product(CO, cone.normal_vec3) * vec3_inner_product(CO, cone.normal_vec3);
	double	root[2];

	if (!root_formula(a, b, c, root))
	{
		printf("here %f, %f\n", root[0], root[1]);
		return (false);
	}
	printf("eles\n");

	t_vec3 P1 = vec3_plus(ray->origin, vec3_scalar_multi(ray->direction, root[0]));
	t_vec3 P2 = vec3_plus(ray->origin, vec3_scalar_multi(ray->direction, root[1]));

	double height1 = vec3_inner_product(vec3_minus(P1, cone.center_point), cone.normal_vec3);
	double height2 = vec3_inner_product(vec3_minus(P2, cone.center_point), cone.normal_vec3);

	if (height1 < 0 || height1 > cone.height) {
		root[0] = 0;
	}
	if (height2 < 0 || height2 > cone.height) {
		root[1] = 0;
	}
	if (root[0] >= 0) {
		printf("return root[0]\n");
		return root[0];
	} else if (root[1] >= 0) {
		printf("return root[1]\n");
		return root[1];
	} else {
		printf("return 0\n");
		return (0); // intersection is behind the ray's origin
	}
}

void	_get_side_normal_vec3(t_cone cone, t_record *record)
{
	t_vec3 PC = vec3_minus(record->point, cone.center_point);
	double cos_a = cone.radius / sqrt(cone.radius*cone.radius + cone.height*cone.height);
	t_vec3 n = vec3_minus(PC, vec3_scalar_multi(cone.normal_vec3, cos_a * vec3_inner_product(PC, cone.normal_vec3) + sqrt(1 - cos_a*cos_a) * sqrt(vec3_inner_product(PC, PC) - vec3_inner_product(PC, cone.normal_vec3) * vec3_inner_product(PC, cone.normal_vec3))));
	double length = sqrt(vec3_inner_product(n, n));
	record->normal_vec3 = vec3_scalar_multi(n, 1 / length); // normalize the vector
}

t_object_type	get_cone_record(t_obj *obj, t_ray *ray, t_record *record)
{
	const t_cone	cone = obj->content.cone;

	record->obj = obj;
	record->point = ray_at(ray, record->t);
	if (cone.co_type == SIDE)
		_get_side_normal_vec3(cone, record);
	if (cone.co_type == BASE)
		record->normal_vec3 = cone.normal_vec3;
	set_face_normal(ray, record);
	record->rgba = cone.rgba;
	return (obj->type);
}
