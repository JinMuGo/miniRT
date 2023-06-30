/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:44:18 by jgo               #+#    #+#             */
/*   Updated: 2023/06/29 13:46:54 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs_bonus.h"
#include "minirt_bonus.h"

t_ray	ray_from_camera(t_camera *camera, const double u, const double v)
{
	t_ray	ray;

	ray.origin = camera->pos;
	ray.direction = vec3_unit(\
					vec3_minus(vec3_plus(vec3_plus(camera->left_bottom, \
						vec3_scalar_multi(camera->horizontal, u)), \
						vec3_scalar_multi(camera->vertical, 1 - v)), \
					camera->pos));
	return (ray);
}

t_ray	ray_init(t_point3 origin, t_vec3 direction)
{
	const t_ray	ray = {origin, direction};

	return (ray);
}

t_point3	ray_at(const t_ray *ray, const double t)
{
	return (vec3_plus(ray->origin, vec3_scalar_multi(ray->direction, t)));
}

void	set_face_normal(const t_ray *ray, t_record *record)
{
	if ((vec3_inner_product(ray->direction, record->normal_vec3) < 0) == false)
		record->normal_vec3 = vec3_scalar_multi(record->normal_vec3, -1);
}
