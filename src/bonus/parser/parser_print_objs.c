/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_print_objs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:10:40 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/20 14:45:46 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "defs.h"
#include "design_patterns.h"

static inline void	_print_sphere(t_sphere sphere)
{
	printf(">>>sphere<<<\n");
	printf("Center point: %f, %f, %f\n", sphere.center_point.x,
		sphere.center_point.y, sphere.center_point.z);
	printf("Diameter: %f\n", sphere.diameter);
	printf("RGB: %f, %f, %f\n", sphere.rgba.r, sphere.rgba.g, sphere.rgba.b);
}

static inline void	_print_plane(t_plane plane)
{
	printf(">>>plane<<<\n");
	printf("Point: %f, %f, %f\n", plane.point.x, plane.point.y, plane.point.z);
	printf("Vec3: %f, %f, %f\n", plane.normal_vec3.x,
		plane.normal_vec3.y, plane.normal_vec3.z);
	printf("RGB: %f, %f, %f\n", plane.rgba.r, plane.rgba.g, plane.rgba.b);
}

static inline void	_print_cylinder(t_cylinder cylinder)
{
	printf(">>>cylinder<<<\n");
	printf("Point: %f, %f, %f\n", cylinder.center_point.x,
		cylinder.center_point.y, cylinder.center_point.z);
	printf("Vec3: %f, %f, %f\n", cylinder.normal_vec3.x,
		cylinder.normal_vec3.y, cylinder.normal_vec3.z);
	printf("diameter: %f\n", cylinder.diameter);
	printf("height: %f\n", cylinder.height);
	printf("RGB: %f, %f, %f\n", cylinder.rgba.r, cylinder.rgba.g,
		cylinder.rgba.b);
}

static inline void	_print_cone(t_cone cone)
{
	printf(">>>cone<<<\n");
	printf("Point: %f, %f, %f\n", cone.center_point.x,
		cone.center_point.y, cone.center_point.z);
	printf("Vec3: %f, %f, %f\n", cone.normal_vec3.x,
		cone.normal_vec3.y, cone.normal_vec3.z);
	printf("radius: %f\n", cone.radius);
	printf("height: %f\n", cone.height);
	printf("RGB: %f, %f, %f\n", cone.rgba.r, cone.rgba.g,
		cone.rgba.b);
}

void	print_objs(t_meta *meta)
{
	t_obj		*current;

	current = meta->objs;
	printf("===objs===\n");
	while (current != NULL)
	{
		if (current->type == SP)
			_print_sphere(current->content.sphere);
		else if (current->type == PL)
			_print_plane(current->content.plane);
		else if (current->type == CY)
			_print_cylinder(current->content.cylinder);
		current = current->next;
	}
}
