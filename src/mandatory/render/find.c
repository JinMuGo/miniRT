/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:19:30 by jgo               #+#    #+#             */
/*   Updated: 2023/06/12 20:24:37 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "render.h"

static inline	t_get_obj_dist obj_dist_func_classifier(t_object_type type)
{
	if (type == SP)
		return (get_sphere_dist);
	if (type == PL)
		return (get_plane_dist);
	return (NULL);
}

static inline	t_get_obj_color obj_color_func_classifier(t_object_type type)
{
	if (type == SP)
		return (get_sphere_color);
	if (type == PL)
		return (get_plane_color);
	return (NULL);
}

// obj, cam.pos, ray.direction
bool find_obj_in_pixel(t_obj	*objs, const t_ray *ray, t_record *record)
{
	t_obj	*obj;
	double	calc_t;
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
			record->obj = &obj->content;
			type = obj->type;
		}
		obj = obj->next;
	}
	if (type == NONE)
		return (false);
	record->rgba = obj_color_func_classifier(type)(record->obj, ray, record);
	return (true);
}
