/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:18:05 by jgo               #+#    #+#             */
/*   Updated: 2023/06/16 18:09:27 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "minirt.h"
#include "utils.h"
#include "render.h"

t_vec3	reflect(t_vec3 a, t_vec3 b)
{
	return (vec3_minus(a, vec3_scalar_multi(b, vec3_inner_product(a, b) * 2)));
}

bool	in_shadow(t_obj *objs, t_record *_record, t_vec3 light_dir,
		double light_len)
{
	const t_ray light_ray = ray_init(vec3_plus(_record->point,
			vec3_scalar_multi(_record->normal_vec3, EPSILON)), light_dir);
    t_record record;

    record.t = light_len;
    return (find_obj_in_pixel(objs, (t_ray *)&light_ray, &record));
}
