/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:36:32 by jgo               #+#    #+#             */
/*   Updated: 2023/06/21 13:46:38 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "light.h"
#include "minirt.h"
#include "render.h"
#include "utils.h"

static inline t_rgba	_diffuse(t_vec3 record_normal_vec3, t_vec3 light_dir,
		t_rgba light_rgba)
{
	return (rgba_scalar_multi(light_rgba,
			fmax(vec3_inner_product(record_normal_vec3, light_dir), 0.0)));
}

static inline t_rgba	_specular(t_vec3 record_normal_vec3, t_vec3 light_dir,
		t_rgba light_rgba, t_vec3 ray_direction)
{
	const double	ksn = 64;
	const double	ks = 0.5;
	const t_vec3	view_dir = vec3_scalar_multi(ray_direction, -1);
	const t_vec3	reflect_dir = reflect(light_dir, record_normal_vec3);
	const double	spec = pow(\
					fmax(vec3_inner_product(view_dir, reflect_dir), 0.0), ksn);

	return (rgba_scalar_multi(rgba_scalar_multi(light_rgba, ks), spec));
}

static inline t_rgba	_spot_light_get(t_obj *objs, t_spot_light *light,
		t_record *record, const t_ray *ray)
{
	t_vec3	light_dir;
	double	light_len;

	light_dir = vec3_minus(light->light_point, record->point);
	light_len = vec3_length(light_dir);
	light_dir = vec3_unit(light_dir);
	if (in_shadow(objs, record, light_dir, light_len))
		return (rgba_init_int(0, 0, 0, 255));
	return (rgba_scalar_multi(rgba_plus(\
			_diffuse(record->normal_vec3, light_dir, light->rgba), \
			_specular(\
				record->normal_vec3, light_dir, light->rgba, ray->direction)),
			light->ratio * LUMEN));
}

t_rgba	phong_lighting(t_meta *meta, t_record *record, const t_ray *ray)
{
	t_list	*spot_light;
	t_rgba	light_rgba;

	spot_light = meta->spot_lights;
	light_rgba = rgba_init_int(0, 0, 0, 255);
	while (spot_light)
	{
		light_rgba = rgba_plus(\
				light_rgba, \
				_spot_light_get(\
					meta->objs, spot_light->content, record, ray));
		spot_light = spot_light->next;
	}
	light_rgba = rgba_plus(\
				light_rgba, \
				rgba_scalar_multi(meta->ambient.rgba, meta->ambient.ratio));
	return (rgba_min(rgba_init_int(0xFF, 0xFF, 0xFF, 0xFF),
			rgba_multi(light_rgba, record->rgba)));
}
