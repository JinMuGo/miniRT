/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:34 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/16 19:13:13 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "render.h"

static double	calculate_infinite_cylinder_t(t_cylinder *cy, t_ray *ray)
{
	double			coeff[3];
	double			root[2];
	bool			root0_vaild;
	bool			root1_vaild;

	get_cylinder_coeff(cy, ray, coeff);
	if (root_formula(coeff[A], coeff[B], coeff[C], root) == false)
		return (0);
	root0_vaild = is_valid_height(root[0], cy, ray);
	root1_vaild = is_valid_height(root[1], cy, ray);
	if (!root0_vaild && !root1_vaild)
		return (0);
	if (root[0] > 0 && root0_vaild)
		return (root[0]);
	if (root[1] > 0 && root1_vaild)
		return (root[1]);
	return (0);
}

static double	calculate_cap_cylinder_t(t_cylinder *cy, t_ray *ray)
{
	double	cap_inter[2];
	bool	top_valid;
	bool	bottom_valid;

	get_top_bot_t(cy, ray, cap_inter);
	top_valid = is_valid_cap(cap_inter[TOP], cy, ray, TOP);
	bottom_valid = is_valid_cap(cap_inter[BOT], cy, ray, BOT);
	if (top_valid && (!bottom_valid || cap_inter[TOP] < cap_inter[BOT]))
	{
		cy->p_type = TOP;
		return (cap_inter[TOP]);
	}
	else if (bottom_valid)
	{
		cy->p_type = BOT;
		return (cap_inter[BOT]);
	}
	return (0);
}

double	get_cylinder_dist(t_obj *obj, const t_ray *ray)
{
	t_cylinder	*cylinder;
	double		infinite_t;
	double		cap_t;

	cylinder = &(obj->content.cylinder);
	cylinder->normal_vec3 = vec3_unit(cylinder->normal_vec3);
	infinite_t = calculate_infinite_cylinder_t(cylinder, (t_ray *)ray);
	cylinder->p_type = INF;
	cap_t = calculate_cap_cylinder_t(cylinder, (t_ray *)ray);

	if ((infinite_t > 0 && cap_t <= 0)
		|| (infinite_t > 0 && cap_t > 0 && infinite_t <= cap_t))
	{
		cylinder->p_type = INF;
		return (infinite_t);
	}
	else if (cap_t > 0)
		return (cap_t);
	return (0);
}

t_object_type	get_cylinder_record(t_obj *obj, t_ray *ray, t_record *record)
{
	const t_cylinder	cylinder = obj->content.cylinder;
	t_vec3				projected_point;

	record->obj = obj;
	record->point = ray_at(ray, record->t);

	if (cylinder.p_type == INF)
		projected_point = vec3_plus(cylinder.center_point,
				vec3_scalar_multi(cylinder.normal_vec3,
					vec3_inner_product(vec3_minus(record->point,
							cylinder.normal_vec3),
						cylinder.normal_vec3)));
	if (cylinder.p_type == TOP)
		projected_point = vec3_plus(cylinder.center_point,
				vec3_scalar_multi(cylinder.normal_vec3,
					cylinder.height / 2));
	if (cylinder.p_type == BOT)
		projected_point = vec3_minus(cylinder.center_point,
				vec3_scalar_multi(cylinder.normal_vec3, cylinder.height / 2));
	record->normal_vec3 = vec3_unit(vec3_minus(record->point, projected_point));
	set_face_normal(ray, record);
	return (obj->type);
}

t_rgba	get_cylinder_color(union u_obj *obj, t_meta *meta, t_record *record)
{
	const t_cylinder	cylinder = obj->cylinder;

	(void)meta;
	(void)record;
	return (cylinder.rgba);
}
