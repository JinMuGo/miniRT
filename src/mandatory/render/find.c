/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:19:30 by jgo               #+#    #+#             */
/*   Updated: 2023/06/16 10:59:12 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"
#include "render.h"

static inline t_get_obj_dist	_obj_dist_func_classifier(t_object_type type)
{
	if (type == SP)
		return (get_sphere_dist);
	if (type == PL)
		return (get_plane_dist);
	if (type == CY)
		return (get_cylinder_dist);
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
	return (NULL);
}

// obj, cam.pos, ray.direction
bool	find_obj_in_pixel(t_obj *objs, t_ray *ray, t_record *record)
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
