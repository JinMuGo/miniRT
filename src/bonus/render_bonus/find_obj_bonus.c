/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_obj_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:19:30 by jgo               #+#    #+#             */
/*   Updated: 2023/06/30 10:48:02 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs_bonus.h"
#include "minirt_bonus.h"
#include "render_bonus.h"

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
		calc_t = obj->get_t(obj, ray);
		if (calc_t && (record->t == 0 || calc_t < record->t))
		{
			record->t = calc_t;
			type = obj->set_r(obj, ray, record);
		}
		obj = obj->next;
	}
	if (type == NONE)
		return (false);
	return (true);
}
