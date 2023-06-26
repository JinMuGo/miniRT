/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:18:31 by jgo               #+#    #+#             */
/*   Updated: 2023/06/26 09:59:34 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "render.h"
#include "utils.h"
#include "light.h"

double	get_sphere_dist(t_obj *obj, const t_ray *ray)
{
	const t_sphere		sphere = obj->content.sphere;
	const t_vec3		c_to_o = vec3_minus(ray->origin, sphere.center_point);
	const t_quad_coeff	coeff = {
		vec3_square_length(ray->direction),
		vec3_inner_product(c_to_o, ray->direction) * 2.0,
		vec3_inner_product(c_to_o, c_to_o) - (sphere.radius * sphere.radius)};
	double				root[2];

	if (root_formula(coeff.a, coeff.b, coeff.c, root) == false)
		return (0);
	if (root[0] > 0)
		return (root[0]);
	if (root[1] > 0)
		return (root[1]);
	return (0);
}

static inline void _set_sphere_uv(t_obj_option *option, t_record *record)
{
	const double phi = atan2(-record->normal_vec3.z, record->normal_vec3.x) + M_PI;
	const double theta = acos(-record->normal_vec3.y);

	option->op.bp.uv.u = phi / (M_PI * 2);
	option->op.bp.uv.v = theta / M_PI;
}

static inline t_rgba _get_bp_color(t_bp *bp, t_record *record)
{
	const int u = bp->uv.u * bp->img->width;
	const int v = (1.0 - bp->uv.v) * bp->img->height;
	int	normal;
	
	bp->rgba = get_img_pixel(bp->img, u, v);
	set_ab_axis_from_c(&bp->right, &bp->up, &record->normal_vec3);
	bp->rgba = rgba_scalar_minus(rgba_scalar_multi(bp->rgba, 2), 1);
	record->normal_vec3 = 
	
	return (bp->rgba);
}

t_object_type	get_sphere_record(t_obj *obj, t_ray *ray, t_record *record)
{
	const t_sphere	sphere = obj->content.sphere;

	record->obj = obj;
	record->point = ray_at(ray, record->t);
	record->normal_vec3 = vec3_scalar_divide(\
				vec3_minus(record->point, sphere.center_point), sphere.radius);
	set_face_normal(ray, record);
	if (obj->option)
	{
		if (obj->option->type == CB)
			record->rgba = get_cb_color(sphere.rgba, obj->option, &record->point);
		else if (obj->option->type == BP)
		{
			_set_sphere_uv(obj->option, record);
			record->rgba = _get_bp_color(&obj->option->op.bp, record);
		}
	}
	else
		record->rgba = sphere.rgba;
	return (obj->type);
}
