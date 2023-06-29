/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_obj_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:19:30 by jgo               #+#    #+#             */
/*   Updated: 2023/06/29 12:27:33 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs_bonus.h"
#include "minirt_bonus.h"
#include "render_bonus.h"

static inline t_get_obj_dist	_obj_dist_func_classifier(t_object_type type)
{
	if (type == SP)
		return (get_sphere_dist);
	if (type == PL)
		return (get_plane_dist);
	if (type == CY)
		return (get_cylinder_dist);
	if (type == CO)
		return (get_cone_dist);
	return (NULL);
}

static inline t_get_obj_record	_obj_record_func_classifier(t_object_type type)
{
	if (type == SP)
		return (get_sphere_record);
	if (type == PL)
		return (get_plane_record);
	if (type == CY)
		return (get_cylinder_record);
	if (type == CO)
		return (get_cone_record);
	return (NULL);
}

// obj, cam.pos, ray.direction
bool	find_obj_in_pixel(t_obj *objs, const t_ray *ray, t_record *record)
{
	t_obj			*obj;
	double			calc_t;
	t_object_type	type;

	obj = objs;
	type = NONE;
	while (obj)
	{
		calc_t = _obj_dist_func_classifier(obj->type)(obj, ray);
		if (calc_t && (record->t == 0 || calc_t < record->t))
		{
			record->t = calc_t;
			type = _obj_record_func_classifier(obj->type)(obj, ray, record);
		}
		obj = obj->next;
	}
	if (type == NONE)
		return (false);
	return (true);
}
