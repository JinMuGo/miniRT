/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:36:32 by jgo               #+#    #+#             */
/*   Updated: 2023/06/29 13:48:06 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs_bonus.h"
#include "light_bonus.h"
#include "minirt_bonus.h"
#include "render_bonus.h"
#include "utils_bonus.h"

static inline t_rgb	_diffuse(t_vec3 record_normal_vec3, t_vec3 light_dir,
		t_rgb light_rgb)
{
	return (vec3_scalar_multi(light_rgb,
			fmax(vec3_inner_product(record_normal_vec3, light_dir), 0.0)));
}

static inline t_rgb	_specular(t_vec3 record_normal_vec3, t_vec3 light_dir,
		t_rgb light_rgb, t_vec3 ray_direction)
{
	const double	ksn = 64;
	const double	ks = 0.5;
	const t_vec3	view_dir = vec3_scalar_multi(ray_direction, -1);
	const t_vec3	reflect_dir = reflect(light_dir, record_normal_vec3);
	const double	spec = pow(\
					fmax(vec3_inner_product(view_dir, reflect_dir), 0.0), ksn);

	return (vec3_scalar_multi(vec3_scalar_multi(light_rgb, ks), spec));
}

static inline t_rgb	_spot_light_get(t_obj *objs, t_spot_light *light,
		t_record *record, const t_ray *ray)
{
	t_vec3	light_dir;
	double	light_len;

	light_dir = vec3_minus(light->light_point, record->point);
	light_len = vec3_length(light_dir);
	light_dir = vec3_unit(light_dir);
	if (in_shadow(objs, record, light_dir, light_len))
		return (rgb_init_int(0, 0, 0));
	return (vec3_scalar_multi(vec3_plus(\
			_diffuse(record->normal_vec3, light_dir, light->rgb), \
			_specular(\
				record->normal_vec3, light_dir, light->rgb, ray->direction)),
			light->ratio * LUMEN));
}

t_rgb	phong_lighting(t_meta *meta, t_record *record, const t_ray *ray)
{
	t_list	*spot_light;
	t_rgb	light_rgb;

	spot_light = meta->spot_lights;
	light_rgb = rgb_init_int(0, 0, 0);
	while (spot_light)
	{
		light_rgb = vec3_plus(\
				light_rgb, \
				_spot_light_get(\
					meta->objs, spot_light->content, record, ray));
		spot_light = spot_light->next;
	}
	light_rgb = vec3_plus(\
				light_rgb, \
				vec3_scalar_multi(meta->ambient.rgb, meta->ambient.ratio));
	return (rgba_min(rgb_init_int(0xFF, 0xFF, 0xFF),
			vec3_multi(light_rgb, record->rgb)));
}
