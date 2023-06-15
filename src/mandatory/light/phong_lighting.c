/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:36:32 by jgo               #+#    #+#             */
/*   Updated: 2023/06/15 17:13:24 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "utils.h"
#include "light.h"
#include "render.h"

static inline t_rgba	__diffuse()
{

}

static inline t_rgba	__specular()
{

}

static inline t_rgba	_spot_light_get(t_meta *meta, t_spot_light *light, t_record *record)
{
	// diffuse;
	t_rgba	diffuse;
	t_vec3	light_dir; // specular도 같이 씀.
	double kd;
	// specular
	const double	ksn = 64;
	const double	ks = 0.5;
	t_rgba	specular;
	t_vec3	view_dir;
	t_vec3	reflect_dir;
	double	spec;
	double	brightness;
	// shadow;
	double	light_len;
	t_ray 	light_ray;

	// diffuse;
	light_dir = vec3_minus(light->light_point, record->point);
	light_len = vec3_length(light_dir);
	light_ray =	ray_init(vec3_plus(record->point, vec3_scalar_multi(record->normal_vec3, EPSILON)), light_dir);
	if (in_shadow(meta->objs, &light_ray, light_len))
		return (rgba_init_int(0, 0, 0, 255));
	light_dir = vec3_unit(light_dir);
	kd = fmax(vec3_inner_product(record->normal_vec3, light_dir), 0.0);
	diffuse = rgba_scalar_multi(light->rgba, kd);
	// specular;
	view_dir = vec3_unit(vec3_scalar_multi(meta->scene.ray.direction, -1));
	reflect_dir = reflect(vec3_scalar_multi(light_dir, -1), record->normal_vec3);
	spec = pow(fmax(vec3_inner_product(view_dir, reflect_dir), 0.0), ksn);
	specular = rgba_scalar_multi(rgba_scalar_multi(light->rgba, ks), spec);
	brightness = light->ratio * LUMEN;

	return (rgba_scalar_multi(rgba_plus(diffuse, specular), brightness));
}

t_rgba	phong_lighting(t_meta *meta, t_record *record)
{
	t_list *spot_light;
	t_rgba	rgba;

	spot_light = meta->spot_lights;
	rgba = rgba_init_int(0, 0, 0, 255);
	while (spot_light)
	{
		rgba = rgba_plus(rgba, _spot_light_get(meta, spot_light->content, record));
		spot_light = spot_light->next;
	}
	rgba = rgba_plus(rgba, rgba_scalar_multi(meta->ambient.rgba, meta->ambient.ratio)); // ambient
	return (rgba_min(rgba_init_int(0xFF, 0xFF, 0xFF, 0xFF), rgba_multi(rgba, record->rgba)));
}
