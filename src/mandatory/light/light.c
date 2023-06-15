/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:18:05 by jgo               #+#    #+#             */
/*   Updated: 2023/06/15 14:39:53 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"
#include "utils.h"

t_vec3	reflect(t_vec3 a, t_vec3 b)
{
	return (vec3_minus(a, vec3_scalar_multi(b, vec3_inner_product(a, b) * 2)));
}

t_rgba	spot_light_get(t_scene *scene, t_spot_light *light, t_record *record)
{
	// diffuse;
	t_rgba	diffuse;
	t_vec3	light_dir;
	double kd;
	// specular
	const double	ksn = 64;
	const double	ks = 0.5;
	t_rgba	specular;
	t_vec3	view_dir;
	t_vec3	reflect_dir;
	double	spec;

	// diffuse;
	light_dir = vec3_unit(vec3_minus(light->light_point, record->point));
	kd = fmax(vec3_inner_product(record->normal_vec3, light_dir), 0.0);
	diffuse = rgba_scalar_multi(light->rgba, kd);
	diffuse = rgba_scalar_multi(diffuse, light->ratio);

	// specular;
	view_dir = vec3_unit(vec3_scalar_multi(scene->ray.direction, -1));
	reflect_dir = reflect(vec3_scalar_multi(light_dir, -1), record->normal_vec3);
	spec = pow(fmax(vec3_inner_product(view_dir, reflect_dir), 0.0), ksn);
	specular = rgba_scalar_multi(rgba_scalar_multi(light->rgba, ks), spec);
	return (rgba_plus(diffuse, specular));
}
