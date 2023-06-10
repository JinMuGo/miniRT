/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:19:30 by jgo               #+#    #+#             */
/*   Updated: 2023/06/10 21:25:03 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"

// obj, cam.pos, ray.direction
bool hit_obj(t_list	*objs, t_ray *ray, t_hit_record *record)
{
	t_list	obj;

	obj = *objs;
	while (obj)
	{


		obj = obj->next;
	}
}
