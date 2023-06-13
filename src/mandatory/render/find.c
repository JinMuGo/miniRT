/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:19:30 by jgo               #+#    #+#             */
/*   Updated: 2023/06/13 18:50:47 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "render.h"

static inline t_get_obj_dist	obj_dist_func_classifier(t_object_type type)
{
	if (type == SP)
		return (get_sphere_dist);
	return (NULL);
}

static inline t_get_obj_record	obj_record_func_classifier(t_object_type type)
{
	if (type == SP)
		return (get_sphere_record);
	return (NULL);
}

static inline t_get_obj_color	obj_color_func_classifier(t_object_type type)
{
	if (type == SP)
		return (get_sphere_color);
	return (NULL);
}

// obj, cam.pos, ray.direction
bool	find_obj_in_pixel(t_obj	*objs, const t_ray *ray, t_record *record)
{
	t_obj			*obj;
	double			calc_t;
	t_object_type	type;

	record->t = 0;
	obj = objs;
	type = NONE;
	while (obj)
	{
		calc_t = obj_dist_func_classifier(obj->type)(obj, ray);
		if (calc_t && (record->t == 0 || calc_t < record->t))
		{
			record->t = calc_t;
			type = obj_record_func_classifier(obj->type)(obj, (t_ray *)ray,
					record);
		}
		obj = obj->next;
	}
	if (type == NONE)
		return (false);
	record->rgba = obj_color_func_classifier(type)(record->obj);
	return (true);
}
