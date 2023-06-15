/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:18:05 by jgo               #+#    #+#             */
/*   Updated: 2023/06/15 14:14:56 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"
#include "utils.h"

t_rgba	spot_light_get(t_scene *scene, t_spot_light *light, t_record *record)
{
	t_rgba	diffuse;
	t_vec3	light_dir;
	double kd;

	light_dir = vec3_unit(vec3_minus(light->light_point, record->point));
	kd = fmax(vec3_inner_product(record->normal_vec3, light_dir), 0.0);
	diffuse = rgba_scalar_multi(light->rgba, kd);
	diffuse = rgba_scalar_multi(diffuse, light->ratio);
	return (diffuse);
}
