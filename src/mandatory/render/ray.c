/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:44:18 by jgo               #+#    #+#             */
/*   Updated: 2023/06/10 20:40:34 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"

t_ray	ray_init(t_camera *camera, double ratio[2])
{
	t_ray	ray;

	ray.origin = camera->pos;
	ray.direction = vec3_unit(
		vec3_minus(vec3_plus(vec3_plus(camera->left_bottom,
		vec3_multi(camera->horizontal, ratio[X])),
		vec3_multi(camera->vertical, ratio[Y])),
		camera->pos));
	return (ray);
}
