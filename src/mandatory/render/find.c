/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:19:30 by jgo               #+#    #+#             */
/*   Updated: 2023/06/11 18:28:12 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "render.h"

static inline	t_get_obj_dist obj_dist_func_classifier(t_object_type type)
{
	if (type == SP)
		return (get_sphere_dist);
}

static inline	t_get_obj_dist obj_color_func_classifier(t_object_type type)
{
	if (type == SP)
		return (get_sphere_color);
}

// obj, cam.pos, ray.direction
bool find_obj_in_pixel(t_obj	*objs, t_ray *ray, t_record *record)
{
	t_obj	*obj;
	double	calc_t;
	t_object_type	type;

	record->t = 0;
	calc_t = 0;
	obj = objs;
	type = NONE;
	while (obj)
	{
		calc_t = obj_dist_func_classifier(obj->type)(obj, ray, record);
		if (calc_t && (record->t == 0 || calc_t < record->t))
		{
			record->t = calc_t;
			type = obj->type;
		}
		obj = obj->next;
	}
	if (type == NONE)
		return (false);
	record->rgba = obj_color_func_classifier(type)(etc.....);
	return (true);
}